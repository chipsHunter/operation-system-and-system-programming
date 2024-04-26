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
const char *getParamInSpecifiedWay(char action, const char* parameter, char* env[]) {
    const char* childPath;
    if(action == GET_INFO_FROM_FUNCTION) {
        childPath = getenv(parameter);
        printf("%s\n", childPath);
    }
    if(action == GET_INFO_FROM_ENV_PARAMETERS) {
        childPath = getParameterFromEnv(parameter, env);
        printf("%s\n", childPath);
    }
    if(action == GET_INFO_FROM_EXTERNAL_VARIABLE) {
        childPath = getParameterFromEnv(parameter, environ);
        printf("%s\n", childPath);
    }
    return childPath;
}
char** reduceEnv(const char** paramList, char* env[]) {

    char** createdEnv = (char**)calloc(ENV_PARAMETERS_COUNT, sizeof(char*));
    for(size_t i = 0; i < ENV_PARAMETERS_COUNT; i++) {
        createdEnv[i] = (char*)calloc(256, sizeof(char));
    }
    for(size_t envSize = 0; envSize < ENV_PARAMETERS_COUNT; envSize++) {
        const char* parameter = getParamInSpecifiedWay(GET_INFO_FROM_FUNCTION, paramList[envSize], env);
        strcpy(createdEnv[envSize], parameter);
    }
    return createdEnv;

}
char** getSpecifiedParamList(const char* filename) {
    char** paramList = (char**)calloc(ENV_PARAMETERS_COUNT, sizeof(char*));
    for(size_t i = 0; i < ENV_PARAMETERS_COUNT; i++) {
        paramList[i] = (char*)calloc(256, sizeof(char));
    }

    FILE* file = fopen(filename, "r");
    char param[256];
    size_t paramCount = 0;
    while ((fgets(param, 256, file)) != NULL) {
        strcpy(paramList[paramCount++], param);
    }

    return paramList;
}
