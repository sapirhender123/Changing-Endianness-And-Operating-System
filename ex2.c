
#include <stdio.h>
#include <string.h>

///function thar write CR/LF according to the arguments
void writeCRLF(const char *CR, const char *LF, int indx, FILE *ptrDest) {
    if (CR != NULL) {
        fwrite(&CR[!indx], 1, 1, ptrDest);
        fwrite(&CR[indx], 1, 1, ptrDest);
    }

    if (LF != NULL) {
        fwrite(&LF[!indx], 1, 1, ptrDest);
        fwrite(&LF[indx], 1, 1, ptrDest);
    }
}

int main(int argc, char *argv[]) {
    // if there is not enough arguments
    if (argc < 3 || argc == 4)
        return 1;

    if (argc == 3) {
        // parse the arguments
        char *sourceFile = argv[1];
        char *destFile = argv[2];
        FILE *ptrSrc;
        ptrSrc = fopen(sourceFile, "rb"); // open the source file
        if (ptrSrc == NULL) {
            return 1;
        }
        FILE *ptrDest; // create a destination file
        ptrDest = fopen(destFile, "wb");
        char buffer[1];
        while (fread(buffer, 1, sizeof(buffer), ptrSrc) != 0) {
            // copy the content from the source file to the destination file
            fwrite(buffer, sizeof(buffer), 1, ptrDest);
        }
        fclose(ptrSrc);
        fclose(ptrDest);
    }
    if ((argc == 5) || argc == 6) { // case number 2 or 3
        // now, there are two cases. The first can be endianness flag, and the second can be an operating system flag.
        // parse the arguments
        int srcWinFlag = !strcmp(argv[3], "-win");
        int srcMacFlag = !strcmp(argv[3], "-mac");
        int srcUnixFlag = !strcmp(argv[3], "-unix");
        if (!srcWinFlag && !srcMacFlag && !srcUnixFlag) return 1;

        int destWinFlag = !strcmp(argv[4], "-win");
        int destMacFlag = !strcmp(argv[4], "-mac");
        int destUnixFlag = !strcmp(argv[4], "-unix");
        if (!destWinFlag && !destMacFlag && !destUnixFlag) return 1;

        // check if there a swap / keep flag, and update his flay accordingly
        int swapFlag = 0;
        if (argc == 6) {
            swapFlag = !strcmp(argv[5], "-swap") || 0 != strcmp(argv[5], "-keep");
        }
        char *sourceFile = argv[1];
        char *destFile = argv[2];
        FILE *ptrSrc;
        ptrSrc = fopen(sourceFile, "rb");
        // if the source file doesn't exist
        if (NULL == ptrSrc) { // Invalid file
            return 1;
        }
        FILE *ptrDest; // create a destination file
        ptrDest = fopen(destFile, "wb");
        // If the 16-bit file represented in big-endian byte order, the BOM will appear as 0xFE 0xFF
        // If the 16-bit file use little-endian order, the BOM will appear as 0xFF 0xFE
        char BOM_buffer[2];
        const char bigBOM[2] = {'\xfe', '\xff'};
        int isBigEndian = 0;
        // reading the first 2 bytes in order to understand if the file is in little or big endian
        fread(&BOM_buffer, sizeof(BOM_buffer), 1, ptrSrc);
        if ((BOM_buffer[0] == bigBOM[0]) && (BOM_buffer[1] == bigBOM[1])) {
            isBigEndian = 1;
        }
        char CR[2];
        char LF[2];
        // write the CR or LF according to the big or little endian
        if (isBigEndian) {
            CR[0] = '\0';
            CR[1] = '\r';  // mac
            LF[0] = '\0';
            LF[1] = '\n';  // unix
        } else {
            CR[0] = '\r';  // mac
            CR[1] = '\0';
            LF[0] = '\n';  // unix
            LF[1] = '\0';
        }
        // indx that will be in use in the program in order to write in the file in big endian or little, accordingly
        int indx = isBigEndian;
        if (swapFlag) {
            // if there is swap flag, the index will be the opposite of what it was,
            // in order to change the order of the write of files
            indx = !isBigEndian;
        }

        if (!isBigEndian) {
            // if it is little endian, the meaning of the index is the opposite, because it should be
            // written in the opposite way.
            indx = !indx;
        }

        // writing the BOM in the beginning of the file
        fwrite(&BOM_buffer[!indx], 1, 1, ptrDest);
        fwrite(&BOM_buffer[indx], 1, 1, ptrDest);

        if (srcWinFlag) { // win - > mac / unix
            // reading 2 chars in UTF-16
            char buffer[2];
            // define lineBreak for each operation system
            while (fread(&buffer, sizeof(buffer), 1, ptrSrc) != 0) {
                // in case of the dest file is mac / unix
                if (destMacFlag || destUnixFlag) {
                    if ((buffer[indx] == CR[indx] && buffer[!indx] == CR[!indx])) {
                        // if the first byte is the same like windows, continue reading
                        fread(&buffer, sizeof(buffer), 1, ptrSrc);
                        if (buffer[indx] == LF[indx] && buffer[!indx] == LF[!indx]) {
                            // found a line break
                            if (destUnixFlag) {
                                writeCRLF(NULL, LF, indx, ptrDest);
                            } else if (destMacFlag) {
                                writeCRLF(CR, NULL, indx, ptrDest);
                            }
                        } else { // if just one part of line break of window is the same
                            writeCRLF(CR, NULL, indx, ptrDest);
                            goto write;
                        }
                    } else { // writing the rest of the file
                        goto write;
                    }
                } else { // dest == win
                    write:
                    fwrite(&buffer[!indx], 1, 1, ptrDest);
                    fwrite(&buffer[indx], 1, 1, ptrDest);
                }
            }
        } else { // unix / mac -> windows or unix - > mac or mac - > unix
            char buffer[2];
            while (fread(&buffer, 2, 1, ptrSrc) != 0) {
                if ((srcMacFlag || srcUnixFlag) && (destWinFlag)) {
                    if ((srcMacFlag) && (buffer[indx] == CR[indx] && buffer[!indx] == CR[!indx])) { // mac - > win
                        // if there is a line break of unix or mac, write accordingly
                        writeCRLF(CR, LF, indx, ptrDest);
                    } else if ((srcUnixFlag) && (buffer[indx] == LF[indx] &&
                                                 buffer[!indx] == LF[!indx])) { // unix - > win
                        writeCRLF(CR, LF, indx, ptrDest);
                    } else { // if it is not an break line char, writing the rest
                        fwrite(&buffer[!indx], 1, 1, ptrDest);
                        fwrite(&buffer[indx], 1, 1, ptrDest);
                    }
                } else if ((srcMacFlag && destUnixFlag) &&
                           ((buffer[indx] == CR[indx]) && (buffer[!indx] == CR[!indx]))) { // mac -> unix
                    writeCRLF(NULL, LF, indx, ptrDest);

                } else if ((srcUnixFlag && destMacFlag) && ((buffer[indx] == LF[indx])) &&
                           ((buffer[!indx] == LF[!indx]))) { // unix - > mac
                    writeCRLF(CR, NULL, indx, ptrDest);
                } else { // If it is not a break line char
                    fwrite(&buffer[!indx], 1, 1, ptrDest);
                    fwrite(&buffer[indx], 1, 1, ptrDest);
                }
            }
        }
        // close the files
        fclose(ptrSrc);
        fclose(ptrDest);
    }

}

