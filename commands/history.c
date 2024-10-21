#include "history.h"

#define MAX_QUEUE_LEN 20
#define MAX_COMMAND_LEN 10
#define MAX_PRINT_LEN 10

typedef struct Queue Queue;
struct Queue{
    char* commands[MAX_QUEUE_LEN];
    size_t size;
} historyQueue;

char historyPath[LEN];

void initHistory(){

    strcpy(historyPath, homeDirectoryPath);
    strcat(historyPath, "/history.txt");

    historyQueue.size = 0;
    for(size_t i = 0; i < MAX_QUEUE_LEN; i++)
        historyQueue.commands[i] = (char*) malloc(sizeof(char) * MAX_COMMAND_LEN);

    FILE* fptr = fopen(historyPath, "r");
    if(fptr == NULL){
        FILE* temp = fopen(historyPath, "w");
        fclose(temp);
        fptr = fopen(historyPath, "r");
    }

    char* line = NULL;
    size_t len = MAX_COMMAND_LEN, pos = 0;
    while(getline(&line, &len, fptr) != -1){

        char copy[MAX_COMMAND_LEN];
        strcpy(copy, line);
        if(strtok(copy, delims) == NULL)
            continue;

        char* findNewline = strchr(line, '\n');
        if(findNewline != NULL)
            *findNewline = '\0';
        strcpy(historyQueue.commands[pos], line);
        pos++;

    }
    fclose(fptr);

    if(line)
        free(line);

    historyQueue.size = pos;


}

void addCommand(char* command){

    if(historyQueue.size != 0 && strcmp(command, historyQueue.commands[historyQueue.size-1]) == 0)
        return;

    if(historyQueue.size == MAX_QUEUE_LEN){
        for(size_t i = 0; i < MAX_QUEUE_LEN-1; i++)
            strcpy(historyQueue.commands[i], historyQueue.commands[i+1]);
        historyQueue.size--;
    }

    strcpy(historyQueue.commands[historyQueue.size], command);
    historyQueue.size++;

    FILE* fptr = fopen(historyPath, "w");
    for(size_t i = 0; i < historyQueue.size; i++){
        fprintf(fptr, "%s\n", historyQueue.commands[i]);
    }
    fclose(fptr);

}

void printHistory(){

    size_t start = 0;
    if(historyQueue.size > MAX_PRINT_LEN)
        start = historyQueue.size - MAX_PRINT_LEN;
    printf("%d\n", (int)start);
    for(size_t i = 0; i < MAX_PRINT_LEN && start + i < historyQueue.size; i++){
        printf("%s\n", historyQueue.commands[start+i]);
    }

}