#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARGS 64

int main() {
    char cmd[MAX_CMD_LEN];
    char *args[MAX_ARGS];
    pid_t pid;
    int status;

    while (1) {
        printf("myshell> ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            break;
        }

        if (cmd[strlen(cmd) - 1] == '\n') {
            cmd[strlen(cmd) - 1] = '\0';
        }

        if (strcmp(cmd, "q") == 0) {
            break;
        }

        if (strlen(cmd) == 0) {
            continue;
        }

        char *token = strtok(cmd, " ");
        int i = 0;
        while (token != NULL) {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("Exec failed");
            exit(1);
        } else {
            wait(&status);
        }
    }

    return 0;
}
