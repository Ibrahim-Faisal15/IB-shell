#include <string.h>
#include "parser.h"


#define MAX_TOKENS 64

char** tokenize(char *input){
    static char *tokens[MAX_TOKENS];
    int i = 0;
    
    tokens[i] = strtok(input, " ");

    while(tokens[i] != NULL && i < MAX_TOKENS - 1){
        i++;
        tokens[i] = strtok(NULL, " ");
    }
    return tokens;
}