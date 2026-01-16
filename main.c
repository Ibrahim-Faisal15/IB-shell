#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdint.h>

#include "parser.h"
#include "commands/commands.h"
#define MAX_INPUT_SIZE 1024

int main()
{
    char buffer[MAX_INPUT_SIZE];

    char **args;
    bool state = true;
    while (state)
    {
        printf("\033[1;36mIB-shell >> \033[0m");
        fgets(buffer, MAX_INPUT_SIZE, stdin);
        // printf("%s\n", buffer);
        if (strlen(buffer) > 0 && buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }

        args = tokenize(buffer);

        if (args[0] == NULL)
        {
            continue;
        }

        // IF USER TYPES EXIT
        if (strcmp(args[0], "exit") == 0 || strcmp(args[0], "Exit") == 0)
        {
            state = false;
        }
        else if (strcmp(args[0], "about") == 0)
        {
            about_cmd();
        }
        else if (strcmp(args[0], "clear") == 0)
        {
            clear_cmd();
        }
        else if (strcmp(args[0], "math") == 0)
        {

            if (args[1] == NULL)
            {
                printf("\033[1;31mPlease enter arguments\033[0m\n");
                continue;
            }
            else if (args[2] == NULL)
            {
                printf("\033[1;31mPlease enter arguments\033[0m\n");
                continue;
            }

            int i = 0;
            while (args[i] != NULL)

            {
                i++;
            }
            // printf("value of i = %d ", i);
            long res = math_cmd(args, i);
            // printf("res == %ld",  res);

            if (res == 1)
            {
                printf("\033[1;31mInvalid Command\033[0m\n");
            }
            else
            {

                printf("%ld\n", res);
            }

            // printf("%d", count);
        }
        else
        {

            pid_t pid = fork();

            if (pid == 0)
            {
                if (execvp(args[0], args) == -1)
                {
                    printf("\033[1;31mCommand not Found: %s\033[0m\n", args[0]);
                }
                exit(EXIT_SUCCESS);
            }
            else if (pid < 0)
            {
                perror("Fork failed");
            }
            else
            {
                wait(NULL);
            }
        }
    }
    return 0;
}