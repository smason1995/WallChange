/*
 * Wallpaper changer
 *
 * author: Sydney Mason
 * version: 05/22/2018
 */

#include<stdio.h>
#include<unistd.h>

int change(char directory[]){
    char *cmd = "feh";
    char *args[5];
    args[0] = "feh";
    args[1] = "--bg-scale";
    args[2] = "--randomize";
    //args[3] = "/home/smason/.wallpapers/";
    args[3] = directory;
    args[4] = NULL;

    if(execvp(cmd, args) == -1){
        return -1;
    }
    else{
        return(0);
    }
}

int main(int argc, char* argv[]){
    printf("%s\n", argv[argc-1]);
    if(change(argv[argc-1]) == -1){
        printf("An error has occured\n");
        return -1;
    }
    return(0);
}
