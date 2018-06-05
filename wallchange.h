/*
 * Header file for wallchange library
 *
 * author: Sydney Mason
 * version: 06/02/2018
 */

#ifndef WALLCHANGE_H
#define WALLCHANGE_H

/*
 * LIBRARIES
 */
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<pthread.h>
#include<sys/stat.h>

/*
 * STRUCTURES
 */
typedef struct node{
    FILE* image;
    struct node* next;
}Node;

/*
 * FUNCTION SIGNATURES
 */
int change(int count, char* arguements[]);
int is_directory(char path[]);
int read_images(char path[], int count);
int image_count(char path[]);
#endif
