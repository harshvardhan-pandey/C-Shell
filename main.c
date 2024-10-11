#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>

size_t longest_common_prefix(char* string1, char* string2){

    size_t ans = 0;

    while(ans < strlen(string1) && ans < strlen(string2)){
        if(string1[ans] != string2[ans])
            break;
        ans++;
    }

    return ans;

}

char* process_directory_name(char* directory, char* home_directory){
    
    size_t n = strlen(home_directory);

    if(longest_common_prefix(directory, home_directory) != n)
        return directory;

    directory[0] = '~';
    memmove(directory + 1, directory + n, strlen(directory + n) + 1); 

    return directory;
}

int main(){

    size_t LEN = 100;
    char* HOME_DIRECTORY = (char*) malloc(sizeof(char) * LEN);
    getcwd(HOME_DIRECTORY, LEN);
    char* USER_NAME = getpwuid(geteuid())->pw_name;
    char* SYSTEM_NAME = (char*) malloc(sizeof(char) * LEN);
    gethostname(SYSTEM_NAME, LEN);

    char* current_directory = (char*) malloc(sizeof(char) * LEN);
    strcpy(current_directory, HOME_DIRECTORY);
    current_directory = process_directory_name(current_directory, HOME_DIRECTORY);

    printf("<%s@%s:%s> ", USER_NAME, SYSTEM_NAME, current_directory);


    return 0;

}