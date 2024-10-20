#include "headers.h"

char* processDirectoryName(char* relativePath){
    
    size_t n = strlen(homeDirectoryPath);

    if(strncmp(relativePath, homeDirectoryPath, n))
        return relativePath;

    relativePath[0] = '~';
    memmove(relativePath + 1, relativePath + n, strlen(relativePath + n) + 1); 

    return relativePath;
}

void prompt(){

    char* relativePath = (char*) malloc(sizeof(char) * LEN);
    getcwd(relativePath, LEN);
    relativePath = processDirectoryName(relativePath);

    printf("<%s@%s:%s> ", userName, systemName, relativePath);

}