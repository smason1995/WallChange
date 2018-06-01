/*
 * Wallpaper changer
 *
 * author: Sydney Mason
 * version: 06/01/2018
 */

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

#define OPT_NUM 5

char* flags[] = {"-r", "--style="};
char* options[OPT_NUM] = {"scale", "tile", "center", "fill", "max"};

int change(int count, char* arguements[]){
    //printf("Entered Change!\n");
    char* cmd = "feh";
    char* args[count];
    int index;
    args[0] = cmd;
    for(index = 1; index < count; index++){
        //printf("Entered change for loop\n");
        //printf("%s\n", arguements[index]);
        if(strcmp(arguements[index], flags[0]) == 0){
            //printf("Found custom flag\n");
            //printf("%s\n", arguements[index]);
            args[index] = "--randomize";
        }
        else if(strstr(arguements[index], flags[1]) != NULL){
            int j;
            for(j = 0; j < OPT_NUM; j++){
                if(strstr(arguements[index], options[j]) != NULL){
                    char background[80];
                    strcpy(background, "--bg-");
                    strcat(background, options[j]);
                    args[index] = background;
                    break;
                }
            }
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

