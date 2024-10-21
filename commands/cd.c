#include "cd.h"

void changeDirectory(char* currentDirectoryPath, char* targetPath){

    int flag = chdir(targetPath);

    if(flag == -1){
        perror("cd failed");
        return;
    }

    strcpy(previousDirectoryPath, currentDirectoryPath);
    getcwd(currentDirectoryPath, LEN);

}

void cd(char* targetPath){

    char* currentDirectoryPath = (char*) malloc(sizeof(char) * LEN);
    getcwd(currentDirectoryPath, LEN);

    if(targetPath == NULL || strcmp(targetPath, "~") == 0)
        changeDirectory(currentDirectoryPath, homeDirectoryPath);

    else if(targetPath[0] == '~'){
        memmove(targetPath, targetPath + 1, LEN);
        changeDirectory(currentDirectoryPath, targetPath);
    }

    else if(strcmp(targetPath, "-") == 0){
        changeDirectory(currentDirectoryPath, previousDirectoryPath);
    }

    else{
        changeDirectory(currentDirectoryPath, targetPath);
    }

}