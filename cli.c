/*
 * Main function
 */

#include<stdio.h>
#include "wallchange.h"

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
