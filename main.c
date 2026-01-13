#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "parser.h"

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
            printf("IB-Shell v1.0 - Built by Ibrahim\n");
        }
        else
        {
            printf("Command not Found %s\n", args[0]);
        }


    }
    return 0;
}