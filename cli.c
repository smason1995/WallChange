/*
 * Main function
 *
 * author: Sydney Mason
 * version 06/01/2018
 */

#include<stdio.h>
#include "wallchange.h"

int main(int argc, char* argv[]){
    //int i;
    //for(i = 1; i < argc; i++){
        //printf("%s\n", argv[i]);
    //}

    int result = change(argc, argv);

    if(result == 1){
        printf("An error has occured\n");
        return 1;
    }
    else if(result == -1){
        printf("No image files found in %s\n", argv[argc-1]);
        return -1;
    }

    return(0);
}
