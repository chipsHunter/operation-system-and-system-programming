
#include "parent.h"

int main(int argc, char* argv[], char* env[]) {

    setlocale(LC_COLLATE, "C");

    printEnvParameters(env);

    int child_number = 0;
    const char* childPath;
    while (1) {
        char action = getAction();

        if(action == EXIT_PARENT) {
            break;
        }
        if(action == GET_INFO_FROM_FUNCTION) {
            childPath = getenv(CHILD_PATH);
            printf("%s\n", childPath);
        }
        if(action == GET_INFO_FROM_ENV_PARAMETERS) {
            childPath = getParameterFromEnv(CHILD_PATH, env);
            printf("%s\n", childPath);
        }
        if(action == GET_INFO_FROM_EXTERNAL_VARIABLE) {
            childPath = getParameterFromEnv(CHILD_PATH, environ);
            printf("%s\n", childPath);
        }
        //pid_t pid = fork();
    }
    return 0;
}
