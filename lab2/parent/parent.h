#ifndef PARENT_PARENT_H
#define PARENT_PARENT_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

#define GET_INFO_FROM_FUNCTION '+'
#define GET_INFO_FROM_ENV_PARAMETERS '*'
#define GET_INFO_FROM_EXTERNAL_VARIABLE '&'
#define EXIT_PARENT 'q'

#define CHILD_PATH "CHILD_PATH"

extern char** environ;

char getAction(void);
int stringComparator(const void* first, const void* second);
void printEnvParameters(char* env[]);
const char* getParameterFromEnv(const char* parameter, char* env[]);
char* valueFromParam(const char* parameter, unsigned long paramNameLen);

#endif //PARENT_PARENT_H
