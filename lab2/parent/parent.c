#include <string.h>
#include "parent.h"

char getAction(void) {
    char action;
    scanf("%c", &action);
    return action;
}
int stringComparator(const void* first, const void* second) {
    return strcmp(*(const char**)first, *(const char**)second);
}

void printEnvParameters(char* env[]) {
    size_t envArrSize = -1;
    while (env[envArrSize + 1] != NULL) {
        ++envArrSize;
    }
    qsort(env, envArrSize, sizeof(char*), stringComparator);

    printf("\nEnvironment variables: \n\n");
    for(size_t size = 0; size <= envArrSize; size++) {
        printf("%s\n", env[size]);
    }
    printf("\n");
}
char* valueFromParam(const char* parameter, const unsigned long paramNameLen) {
    char* paramValue = parameter;
    unsigned long paramLen = strlen(parameter);
    size_t shifted;
    for(size_t ptrToShift = 0; ptrToShift < paramLen - paramNameLen; ptrToShift++) {
        shifted = ptrToShift + paramNameLen + 1;
        paramValue[ptrToShift] = paramValue[shifted];
    }
    return paramValue;
}
const char* getParameterFromEnv(const char* parameterName, char* env[]) {
    unsigned long paramNameLen = strlen(parameterName);
    for (size_t envSize = 0; env[envSize] != NULL; envSize++) {
        int equalParamName = 1;
        for (size_t i = 0; i < paramNameLen; i++) {
            if (env[envSize][i] != parameterName[i]) {
                equalParamName = 0;
                break;
            }
        }
        if(equalParamName) {
            return valueFromParam(env[envSize], paramNameLen);
        }
    }
    return NULL;
}
