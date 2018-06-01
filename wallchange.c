/*
 * Wallpaper changer
 *
 * author: Sydney Mason
 * version: 05/22/2018
 */

//Imported libraries
//#include<stdio.h>
//#include<unistd.h>
#include "wallchange.h"

//Takes command line arguments and the directory to work from
/*
 * Takes command line arguments and the directory to pull from
 * 
 * Functions return 0 if successful and -1 if failed
 * 
 * cmd - used to call feh
 * args[] = char array that sets up command line call to feh
 * index - index the positions of args and arguements
 */
int change(int count, char* arguements[]){
    printf("Entered Change!\n");
    char* cmd = "feh";
    char* args[count];
    int index;
    args[0] = cmd;
    for(index = 1; index < count; index++){
        printf("Entered change for loop\n");
        printf("%s\n", arguements[index]);
        if(strcmp(arguements[index], "-r") == 0){
            printf("Found custom flag\n");
            printf("%s\n", arguements[index]);
            args[index] = "--randomize";
        }
        else{
            args[index] = arguements[index];
        }
    }
    args[count] = NULL;

    if(execvp(cmd, args) == -1){
        return -1;
    }
    else{
        return(0);
    }
}

