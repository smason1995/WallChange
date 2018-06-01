/*
 * Wallpaper changer
 *
 * author: Sydney Mason
 * version: 05/22/2018
 */

#include<stdio.h>
#include<unistd.h>

int change(int count, char* arguements[]){
    char* cmd = "feh";
    char* args[count];
    int i;
    args[0] = cmd;
    for(i = 1; i < count; i++){
        args[i] = arguements[i];
    }
    args[count] = NULL;

    if(execvp(cmd, args) == -1){
        return -1;
    }
    else{
        return(0);
    }
}

int main(int argc, char* argv[]){
    int i;
    for(i = 1; i < argc; i++){
        printf("%s\n", argv[i]);
    }

    if(change(argc, argv) == -1){
        printf("An error has occured\n");
        return -1;
    }

    return(0);
}