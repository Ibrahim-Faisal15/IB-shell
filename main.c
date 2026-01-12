#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_INPUT_SIZE 1024

int main(){
    char buffer[MAX_INPUT_SIZE];
    bool state = true;
    while (state)
    {   
        printf("IB-shell>>");
        fgets(buffer, MAX_INPUT_SIZE, stdin);
        // printf("%s\n", buffer);
        buffer[strlen(buffer)-1] = '\0'; 
        if (strcmp(buffer, "exit") == 0 || strcmp(buffer, "Exit") == 0)
        {
            state = false;
        }else{
            printf("Command not Found!\n");
        }
        

    }
    return 0;
}