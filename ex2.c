//208414573 Sapir Hender
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    //todo special cases

    if (argc < 3 || argc == 4)
        return 1;

    // 1. if we are in case 1, we get a source file name and a destination file name, we just have to copy the source

    if (argc == 3) {
        // parse the arguments
        char *sourceFile = argv[1];
        char *destFile = argv[2];

        FILE *ptrSrc;
        // open the source file
        ptrSrc = fopen(sourceFile, "rb");
        if (ptrSrc == NULL) {
            return 1;
        }

        // create a destination file
        FILE *ptrDest;
        ptrDest = fopen(destFile, "wb");
        // create a buffer
        char buffer[1];
        while (fread(buffer, 1, sizeof(buffer), ptrSrc) != 0) {
            // copy the content from the source file to the destination file
            fwrite(buffer, sizeof(buffer), 1, ptrDest);
        }
        fclose(ptrSrc);
        fclose(ptrDest);
    }
    if ((argc == 6) || argc == 5) { // case number 2 or 3
        // now, there are two cases. The first can be endianness flag, and the second can be an operating system flag
        // case 1 - change of operating system and a linebreak.
        int srcWinFlag = !strcmp(argv[3], "-win");
        int srcMacFlag = !strcmp(argv[3], "-mac");
        int srcUnixFlag = !strcmp(argv[3], "-unix");
        if (!srcWinFlag && !srcMacFlag && !srcUnixFlag) return 1;

        int destWinFlag = !strcmp(argv[4], "-win");
        int destMacFlag = !strcmp(argv[4], "-mac");
        int destUnixFlag = !strcmp(argv[4], "-unix");
        if (!destWinFlag && !destMacFlag && !destUnixFlag) return 1;

        int swapFlag = 0;
        if (argc == 6)
            swapFlag = !strcmp(argv[5], "-swap") || 0 != strcmp(argv[5], "-keep");

        const char CR[2] = "\0\r";  // mac
        const char LF[2] = "\0\n";  // unix

        //parse arguments
        char *sourceFile = argv[1];
        char *destFile = argv[2];
        FILE *ptrSrc;
        ptrSrc = fopen(sourceFile, "rb");
        if (NULL == ptrSrc) {
            // Invalid file
            return 1;
        }

        // create a destination file
        FILE *ptrDest;
        ptrDest = fopen(destFile, "wb");

        //If the 16-bit file represented in big-endian byte order, the BOM will appear as 0xFE 0xFF
        //If the 16-bit file use little-endian order, the BOM will appear as 0xFF 0xFE
        char BOM_buffer[2];
        const char bigBOM[2] = "\xFE\xFF";
        int isBigEndian = 0;
        fread(&BOM_buffer, sizeof(BOM_buffer), 1, ptrSrc);
        if ((BOM_buffer[0] == bigBOM[0]) && (BOM_buffer[1] == bigBOM[1])) {
            isBigEndian = 1;
        }
        int indx = isBigEndian; //
        if (swapFlag) {
            indx = !isBigEndian;
        }

        fwrite(&bigBOM[!indx], 1, 1, ptrDest);
        fwrite(&bigBOM[indx], 1, 1, ptrDest);

        if (srcWinFlag) { // win - > mac / unix
            // reading 2 chars in UTF-16
            char buffer[2];
            // define lineBreak for each operation system
            while (fread(&buffer, sizeof(buffer), 1, ptrSrc) != 0) {
                // in case of src == window
                // if it is little endian
                if ((buffer[isBigEndian] == CR[isBigEndian] && buffer[!isBigEndian] == CR[!isBigEndian])) {
                    fread(&buffer, sizeof(buffer), 1, ptrSrc);
                    if (buffer[isBigEndian] == LF[isBigEndian] && buffer[!isBigEndian] == LF[!isBigEndian]) {
                        if (destUnixFlag) {
                            fwrite(&LF[!indx], 1, 1, ptrDest);
                            fwrite(&LF[indx], 1, 1, ptrDest);
                        } else if (destMacFlag) {
                            fwrite(&CR[!indx], 1, 1, ptrDest);
                            fwrite(&CR[indx], 1, 1, ptrDest);
                        }
                    } else {
                        fwrite(&CR[!indx], 1, 1, ptrDest);
                        fwrite(&CR[indx], 1, 1, ptrDest);
                        goto write;
                    }
                } else {
                    write:
                    fwrite(&buffer[!indx], 1, 1, ptrDest);
                    fwrite(&buffer[indx], 1, 1, ptrDest);
                }
            }
        } else { // unix / mac -> windows or unix - > mac or mac - > unix
            char buffer[2];
            while (fread(&buffer, sizeof(buffer), 1, ptrSrc) != 0) {
                // in case of dst == window
                // unix / mac - > window
                if ((srcMacFlag || srcUnixFlag) && (destWinFlag)) {
                    if ((buffer[0] == CR[0] && buffer[1] == CR[1]) || (buffer[0] == LF[0] &&
                                                                       buffer[1] == LF[1])) {
                        fwrite(&CR[indx], 1, 1, ptrDest);
                        fwrite(&CR[!indx], 1, 1, ptrDest);
                        fwrite(&LF[indx], 1, 1, ptrDest);
                        fwrite(&LF[!indx], 1, 1, ptrDest);
                    } else { // if it is not an break line char
                        fwrite(&buffer[indx], 1, 1, ptrDest);
                        fwrite(&buffer[!indx], 1, 1, ptrDest);
                    }
                } else if ((srcMacFlag && destUnixFlag) &&
                           ((buffer[0] = CR[0]) && (buffer[1] == CR[1]))) { // mac -> unix
                    fwrite(&LF[indx], 1, 1, ptrDest);
                    fwrite(&LF[!indx], 1, 1, ptrDest);
                } else if ((srcUnixFlag && destMacFlag) && ((buffer[0] == LF[0])) &&
                           ((buffer[1] == LF[1]))) { // unix - > mac
                    fwrite(&CR[indx], 1, 1, ptrDest);
                    fwrite(&CR[!indx], 1, 1, ptrDest);
                } else { // If it is not a break line char
                    fwrite(&buffer[indx], 1, 1, ptrDest);
                    fwrite(&buffer[!indx], 1, 1, ptrDest);
                }
            }
        }
        fclose(ptrSrc);
        fclose(ptrDest);
    }

}

