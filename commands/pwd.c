#include "pwd.h"

void replaceTilde(char *str) {
    char buffer[LEN + 10] = {'\0'};
    char *tildePos = strchr(str, '~');
    if (tildePos != NULL) {
        strcat(buffer, "/home/");
        strcat(buffer, userName);
        strcat(buffer, tildePos + 1);
        strcpy(str, buffer);
    }
}

void addSlash(char * str){
    char buffer[LEN + 2] = {'\0'};
    char *slashPos = strchr(str, '/');
    if (slashPos != str) {
        strcat(buffer, "/");
        strcat(buffer, str);
        strcpy(str, buffer);
    }
}

void pwd(){

    char* currentDirectoryPath = (char*) malloc(sizeof(char) * LEN);
    getcwd(currentDirectoryPath, LEN);
    currentDirectoryPath = processDirectoryName(currentDirectoryPath); //from prompt
    replaceTilde(currentDirectoryPath);

    if(currentDirectoryPath[0] != '/'){
        char* temp = (char*) malloc(sizeof(char) * (strlen(currentDirectoryPath) + 2));
        temp[0] = '/';
        strcat(temp, currentDirectoryPath);
        currentDirectoryPath = temp;
    }
    
    printf("%s\n", currentDirectoryPath);

}