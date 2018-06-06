/*
 * Wallpaper changer
 *
 * author: Sydney Mason
 * version: 06/02/2018
 */

#include "wallchange.h"

#define OPT_NUM 5
#define IMG_EXT 3

int num_of_images;

char* flags[] = {"-r", "--style=", "-c", "--time=", "--kill"};
char* options[OPT_NUM] = {"scale", "tile", "center", "fill", "max"};
char* image_extensions[IMG_EXT] = {".jpg", ".jpeg", ".png"};

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
int change(int count, char* arguements[]){
    char* cmd = "feh";
    char* args[count];
    int index;
    args[0] = cmd;
    for(index = 1; index < count; index++){
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
            int check = is_directory(arguements[index]);
            if(check == 0){
                if(image_count(arguements[index]) > 0){
                    args[index] = arguements[index];
                }
                else{
                    return -1;
                }
            }
            else if(check == 1){
                args[index] = arguements[index];
            }
            else if(check == -1){
                return -1;
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
 * returns 1 if path is a regular file
 * returns -1 if path doesn't exist or is invalid input
 */
int is_directory(char path[]){
    struct stat dir_check;
    stat(path, &dir_check);
    if(S_ISDIR(dir_check.st_mode) == 1){
        return 0;
    }
    else if(S_ISREG(dir_check.st_mode) == 1){
        int i;
        for(i = 0; i < IMG_EXT; i++){
            if(strstr(path, image_extensions[i])){
                return 1;
            }
        }
        return -1;
    }
    else{
        return -1;
    }
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
            int i;
            for(i = 0; i < IMG_EXT; i++){
                if(strstr(entry->d_name, image_extensions[i])){
                    image_count++;
                }
            }
        }
    }
    closedir(dp);
    return image_count;
}
