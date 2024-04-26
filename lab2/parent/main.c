
#include <sys/wait.h>
#include "parent.h"

int main(int argc, char* argv[], char* env[]) {

    setlocale(LC_COLLATE, "C");

    printEnvParameters(env);

    int child_number = 0;
    const char* childNameTemplate = "child_";
    const char* childPath;
    while (1) {
        char action = getAction();

        if(action == EXIT_PARENT) {
            break;
        }

        childPath = getParamInSpecifiedWay(action, CHILD_PATH, env);
        pid_t pid = fork();
        waitpid(-1, NULL, WNOHANG);
    }
    return 0;
}
