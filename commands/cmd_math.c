
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commands.h"

long math_cmd(char **arg, int count)
{

    char *opr = arg[1];
    long result = 0;
    long product = 1;

    if (strcmp(opr, "add") == 0)
    {

        for (int i = 2; i < count; i++)
        {
            result += atoi(arg[i]);
        }
        return result;
    }
    else if (strcmp(opr, "sub") == 0)

    {
        result = atoi(arg[2]);
        for (int i = 3; i < count; i++)
        {
            result -= atoi(arg[i]);
        }
        return result;
    }
    else if (strcmp(opr, "mul") == 0)
    {
        for (int i = 2; i < count; i++)
        {
            product *= atoi(arg[i]);
        }
        return product;
    }

    else
    {
        return 1;
    }
}
