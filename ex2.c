// 208414573 Sapir Hender
#include <stdio.h>

void main(int argc, char *argv[]) {
    // 1. if we are in case 1, we get a source file name and a destination file name, we just have to copy the source
    if (argc == 3) {
        // if there is no argument
        if (argv[1] == NULL) {
            return;
        }
        else {
            // parse the arguments
            sourceFile = argv[1];
            destFile = argv[2];
            // if there is no such a file
            if (fSource != NULL) {
                // open the source file
                fSource = fopen(sourceFile, "r");
            } else {
                return;
            }
            // create a destination file
            fDest = fopen(destFile, "w");
            // create a buffer
            char buffer[1024];
            while (fSourece != EOF) {
                // copy the content from the source file to the destination file
                fread(buffer, sizeof(buffer), 1, fSource);
                fwrite(buffer, sizeof(buffer), 1, fDest);
            }
        }
    }
}