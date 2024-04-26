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
#define ENV_PARAMETERS_COUNT 9

extern char** environ;

char getAction(void);
int stringComparator(const void* first, const void* second);
void printEnvParameters(char* env[]);
const char* getParameterFromEnv(const char* parameter, char* env[]);
char* valueFromParam(const char* parameter, unsigned long paramNameLen);
const char* getParamInSpecifiedWay(char action, const char* parameter, char* env[]);
char** getSpecifiedParamList(const char* filename);
char** reduceEnv(const char** paramList, char* env[]);

#endif //PARENT_PARENT_H
