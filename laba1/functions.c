#include "functions.h"
char* getPath(int argc, char* argv[]) {
    char* path = (char*)calloc(256, sizeof(char));
    const char* default_path = "/home/hvorostok/lab_osisp/laba1";
    char first_symb = argv[argc - 1][0];
    if(first_symb == '-' || argc == 1) {
        strcpy(path, default_path);
    } else {
        if(first_symb == '/') {
            strcpy(path, argv[argc - 1]);
        } else {
            strcpy(path, default_path);
            path[strlen(path)] = '/';
            strcat(path, argv[argc - 1]);
        }
    }
    return path;
}

char* printErrorMessage(int errorCode) {
    switch (errorCode) {
        case(EACCES): {
            return "Denied access: ";
        }
        case(EFAULT): {
            return  "Bad address: ";
        }
        case(ENOENT): {
            return "Not exists or NULL path provided: ";
        }
        case(ENOTDIR): {
            return "Not a directory: ";
        }
        case(ENOMEM): {
            return "Insufficient memory allocation: ";
        }
        default:
            return "Error with: ";
    }
}

int printAllWithSpecTypeRecursively(const char *path, int regularFileFlag, int directoryFlag, int symbolicLinkFlag, int sortFlag) {
    struct dirent** direntNames;
    int countOfDirectories;
    if(sortFlag == 1)
        countOfDirectories = scandir(path, &direntNames, 0, alphasort);
    else
        countOfDirectories = scandir(path, &direntNames, 0, 0);
    if(countOfDirectories == -1) {
        printf("%s %s\n", printErrorMessage(errno), path);
        return -1;
    }
    for(size_t i = 0; i < countOfDirectories; i++) {
        if(direntNames[i]->d_name[0] == '.') continue;
        char *absolutePath = (char*)calloc(PATH_MAX, sizeof(char));
        strcpy(absolutePath, path);
        if(strlen(absolutePath) != 1)
            absolutePath[strlen(absolutePath) ] = '/';
        strcat(absolutePath, direntNames[i]->d_name);
        struct stat fStat;
        int readingResult;
        if((readingResult = lstat(absolutePath, &fStat)) != 0) {
            printf("%s %s\n", printErrorMessage(errno), absolutePath);
            continue;
        }
        if((fStat.st_mode & S_IFMT) == S_IFREG && regularFileFlag ||
           (fStat.st_mode & S_IFMT) == S_IFDIR && directoryFlag ||
           S_ISLNK(fStat.st_mode) && symbolicLinkFlag) {
            printf("%s\n", absolutePath);
        }
        if ((fStat.st_mode & S_IFMT) == S_IFDIR && strlen(absolutePath) < 255) {
            int subRecursiveResult = printAllWithSpecTypeRecursively(absolutePath, regularFileFlag, directoryFlag, symbolicLinkFlag, sortFlag);
            if(subRecursiveResult != 0) {
                printf("%s %s\n", printErrorMessage(errno), absolutePath);
                continue;
            }
        }
    }
    return 0;
}
