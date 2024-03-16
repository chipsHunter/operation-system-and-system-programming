#ifndef LABA1_FUNCTIONS_H
#define LABA1_FUNCTIONS_H

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <asm-generic/errno.h>
#include <errno.h>

char* getPath(int argc, char* argv[]);
char* printErrorMessage(int errorCode);
int printAllWithSpecTypeRecursively(const char *path, int regularFileFlag, int directoryFlag, int symbolicLinkFlag, int sortFlag);


#endif //LABA1_FUNCTIONS_H
