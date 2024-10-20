#include "echo.h"

void echo(char* token){
    token = strtok(NULL, delims);
    while(token != NULL){
        printf("%s ", token);
        token = strtok(NULL, delims);
    }
    printf("\n");
}