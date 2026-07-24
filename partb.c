#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    // TODO: Complete and document
     if (argc != 2)
    {
        fprintf(stderr, "USAGE: partc FILEIN\n");
        return 1;
    }

    int pipefd[2];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    
    if (pid > 0)
    {
        close(pipefd[0]);               

        dup2(pipefd[1], STDOUT_FILENO); 

        close(pipefd[1]);

        char *args[] = {
            "./parta",
            argv[1],
            NULL
        };

        execv("./parta", args);

        perror("execv");
        exit(1);
    }
    
    else
    {
        close(pipefd[1]);          

        dup2(pipefd[0], STDIN_FILENO); 

        close(pipefd[0]);

        char *args[] = {
            "sort",
            "-t,",
            "-k2",
            "-n",
            NULL
        };

        execvp("sort", args);

        perror("execvp");
        exit(1);
    }

}
