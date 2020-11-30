//208414573 Sapir Hender
#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[]) {
    //todo special cases

    // 1. if we are in case 1, we get a source file name and a destination file name, we just have to copy the source
    if (argc == 3) {
        // if there is no argument
        if (argv[1] == NULL) {
            return;
        } else {
            // parse the arguments
            char *sourceFile = argv[1];
            char *destFile = argv[2];

            FILE *ptrSrc;
            // open the source file
            ptrSrc = fopen(sourceFile, "rb");

            // create a destination file
            FILE *ptrDest;
            ptrDest = fopen(destFile, "wb");
            // create a buffer
            char buffer[1024];
            while (fread(buffer, sizeof(buffer), 1, ptrSrc) != 0) {
                // copy the content from the source file to the destination file
                fwrite(buffer, sizeof(buffer), 1, ptrDest);
            }
        }
    }
    if ((argc == 5) || argc == 4) { // case number 2 or 3
        // now, there are two cases. The first can be endianness flag, and the second can be an operating system flag
        // case 1 - change of operating system and a linebreak.
        int srcWinFlag = !strcmp(argv[3], "-win");
        int srcMacFlag = !strcmp(argv[3], "-mac");
        int srcUnixFlag = !strcmp(argv[3], "-unix");
        int destWinFlag = !strcmp(argv[4], "-win");
        int destMacFlag = !strcmp(argv[4], "-mac");
        int destUnixFlag = !strcmp(argv[4], "-unix");
        //const unsigned int lineBreakWin = 0x000d000a;
        const unsigned int lineBreakMac = 0x000d;
        const unsigned int lineBreakUnix = 0x000a;
        char lineBreakWin[2] = "\r\n";
        //parse arguments
        char *sourceFile = argv[1];
        char *destFile = argv[2];
        FILE *ptrSrc;
        ptrSrc = fopen(sourceFile, "rb");
        // create a destination file
        FILE *ptrDest;
        ptrDest = fopen(destFile, "wb");
        // create a buffer
        if (srcWinFlag) { // win - > mac / unix
            // reading 2 chars in UTF-16
            char buffer[2];
            // define lineBreak for each operation system
            while (fread(&buffer, sizeof(buffer), 1, ptrSrc) != 0) {
                // in case of src == window
                if (*buffer == lineBreakMac) {
                    if (destMacFlag) {
                        buffer = lineBreakMac;
                    } else { // unix = dest
                        buffer = lineBreakUnix;
                    }
                }
                fwrite(&buffer, sizeof(buffer), 1, ptrDest);
            }
        } else { // unix / mac -> windows or unix - > mac or mac - > unix
            char buffer[2];
            while (fread(&buffer, sizeof(buffer), 1, ptrSrc) != 0) {
                // in case of src == window
                if ((srcMacFlag || srcUnixFlag) && (destWinFlag)) {
                    if (!strcmp(buffer,lineBreakMac) == 0) {
                        fwrite(&lineBreakWin, sizeof(lineBreakWin), 1, ptrDest);
                    }
                } else if (srcMacFlag && destUnixFlag) {
                    fwrite(&lineBreakUnix, sizeof(lineBreakUnix), 1, ptrDest);
                } else if (srcUnixFlag && destMacFlag) {
                    fwrite(&lineBreakMac, sizeof(lineBreakMac), 1, ptrDest);
                }
            }
        }
    }
    if (argc == 5) {


    }
}

