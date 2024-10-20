#include "headers.h"



int main(){

    char* homeDirectoryPath = (char*) malloc(sizeof(char) * LEN);
    getcwd(homeDirectoryPath, LEN);

    while(true){
        prompt(homeDirectoryPath);
        scanf("")
    }

    return 0;

}