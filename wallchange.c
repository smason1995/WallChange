/*
 * Wallpaper changer
 *
 * author: Sydney Mason
 * version: 06/02/2018
 */

#include "wallchange.h"

/*
 * Takes command line arguments and the directory to pull from
 * 
 * returns 0 if successful
 * returns 1 if failed
 * returns -1 if no image files found
 * 
 * cmd - used to call feh
 * args[] = char array that sets up command line call to feh
 * index - index the positions of args and arguements
 */

#define OPT_NUM 5
#define IMG_EXT 3

int num_of_images;

char* flags[] = {"-r", "--style=", "-c", "--time=", "--kill"};
char* options[OPT_NUM] = {"scale", "tile", "center", "fill", "max"};
char* image_extensions[IMG_EXT] = {".jpg", ".jpeg", ".png"};

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
            printf("Found custom flag\n");
            printf("%s\n", arguements[index]);
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
        else if(strcmp(arguements[index], flags[2]) == 0){
            printf("This will add slideshow capabilities\n");
        }
        else if(strstr(arguements[index], flags[3]) != NULL){
            printf("This will add timer capabilities\n");
        }
        else if(strcmp(arguements[index], flags[4]) == 0){
            printf("This flag will kill the wallchange thread\n");
        }
        else{
            if(is_directory(arguements[index]) == 0){
                if(image_count(arguements[index]) > 0){
                    args[index] = arguements[index];
                }
                else{
                    return -1;
                }
            }
        }
    }
    args[count] = NULL;

    if(execvp(cmd, args) == -1){
        return 1;
    }
    else{
        return(0);
    }
}

/*
 * Checks if path is a directory
 *
 * returns 0 if path is directory and exists
 * returns 1 if path is image file
 * returns -1 if path doesn't exist or is invalid input
 */
int is_directory(char path[]){
    return 0;
}

/*
 * Reads in image files from a given path
 *
 * returns 0 if successful
 * returns 1 if failed
 */
int read_images(char path[], int count){
    return 0;
}

/*
 * Counts the number of images in a directory
 *
 * returns the number of image files in a directory
 */
int image_count(char path[]){
    int image_count = 0;
    DIR* dp;
    struct dirent* entry;
    dp = opendir(path);
    while((entry = readdir(dp)) != NULL){
        if(entry->d_type == DT_REG){
            if(strstr(entry->d_name, ".jpg") ||
                    strstr(entry->d_name, ".png") ||
                    strstr(entry->d_name, ".jpeg")){
                image_count++;
            }
        }
    }
    closedir(dp);
    return image_count;
}
