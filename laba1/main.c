#include "functions.h"

int main(int argc, char* argv[]) {
    int result;
    int symbolicLinkFlag = 0, directoryFlag = 0, regularFileFlag = 0, sortFlag = 0;
    while ((result = getopt(argc, argv, "ldfs")) != -1) {
        switch (result) {
            case 'l': {
                symbolicLinkFlag = 1;
                break;
            }
            case 'd': {
                directoryFlag = 1;
                break;
            }
            case 'f': {
                regularFileFlag = 1;
                break;
            }
            case 's': {
                sortFlag = 1;
                break;
            }
            default: {
                printf("You've passed wrong params!\n");
                return 2;
            }
        }
    }
    char* path = getPath(argc, argv);
    printAllWithSpecTypeRecursively(path, regularFileFlag, directoryFlag, symbolicLinkFlag, sortFlag);
    free(path);
    return 0;
}
