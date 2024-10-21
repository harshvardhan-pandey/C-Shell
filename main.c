#include "headers.h"

char delims[3] = " \t\n";
char previousDirectoryPath[LEN] = "\0";
char homeDirectoryPath[LEN];
char userName[LEN];
char systemName[LEN];

void runCommand(char* input){

    char* copy = (char*) malloc(sizeof(char) * (strlen(input) + 1));
    strcpy(copy, input);

    char* token;
    token = strtok(copy, delims);

    if(strcmp(token, "echo") == 0){
        addCommand(token);
        echo(token);
    }

    else if(strcmp(token, "pwd") == 0){
        addCommand(token);
        pwd();
    }

    else if(strcmp(token, "cd") == 0){

        addCommand(token);
        char* targetPath;
        targetPath = strtok(NULL, delims);

        token = strtok(NULL, delims);
        if(token != NULL){
            perror("-bash: cd: too many arguments\n");
            return;
        }

        cd(targetPath);

    }

    else if(strcmp(token, "exit") == 0){
        addCommand(token);
        exit(0);
    }

    else if(strcmp(token, "history") == 0){
        addCommand(token);
        printHistory();
    }

    else{
        fprintf(stderr, "%s: command not found\n", token);
    }

}

int main(){

    getcwd(homeDirectoryPath, LEN);
    strcpy(userName,getpwuid(geteuid())->pw_name);
    gethostname(systemName, LEN);
    initHistory();

    while(true){

        prompt(homeDirectoryPath);

        char* input = (char*) malloc(sizeof(char) * 4096);
        if(fgets(input, 4096, stdin) == NULL)
            break;
        char* searchNewline = strchr(input, '\n');
        if(searchNewline)
            *searchNewline = '\0';

        bool isEmpty = true;
        for(size_t i = 0; input[i] != '\0' && isEmpty; i++)
            if(input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
                isEmpty = false;

        if(isEmpty)
            continue;


        runCommand(input);
        free(input);

    }

    return 0;

}