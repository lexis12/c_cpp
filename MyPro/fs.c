//
// Created by alex on 30.09.2019.
//

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "fs.h"
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "strings.h"

void sort_dir (struct dirent **list,int count){

    for (int k = 0; k < count; ++k ){
        int i = k;
        while (i >= 0 && (strcasecmp(list[i]->d_name, list[i + 1]->d_name) > 0)){
            struct dirent *tmp1;
            tmp1 = list[i];
            list[i] = list[i + 1];
            list[i + 1] = tmp1;
            --i;
        }
    }
}
void listdir (char* path){

    struct dirent *pDen = NULL;
    struct dirent **list;
    struct stat fStat;
    int list_len = 200;
    int count =0;
    char f_path [255];

    String *str = (String*)(malloc(sizeof(String)));;






    //return;

    DIR *pDir = opendir(path);
    if (pDir == NULL) return;

    list = (struct dirent** ) malloc(list_len * sizeof(struct dirent*));
    if (list == NULL) {
        free(pDen);
        closedir(pDir);
        return;
    }



    while (pDen = readdir(pDir),pDen) {

        if (count == list_len) {
            list_len *= 2;
            list = (struct dirent **) realloc(list, list_len * sizeof(struct dirent *));
            if (list == NULL) {
                free(list);
                free(pDen);
                return;
            }
        }

        list[count++] = pDen;
    }




    sort_dir(list,count-1);

    int h = true;  //hiden files
    for (int i = 0; i < count; ++i) {
        if (!h && list[i]->d_name[0] == '.') continue;

        sprintf(f_path, "%s%s", path, list[i]->d_name);
        stat(f_path, &fStat);
        printf("%6ld ", fStat.st_size);

        if (list[i]->d_type == 4)
        printf("\033[1;34m%s\n\033[0m", list[i]->d_name);
        else if (list[i]->d_type == 10)
            printf("\033[1;36m%s->\n\033[0m", list[i]->d_name);
        else
        printf("%s\n", list[i]->d_name);
    }


    list[count] = NULL;
    free(pDen);
    closedir(pDir);

    free (str->text);
    free(str);
    /*
    n = scandir(".",&pDen,0,alphasort);
    if (n < 0)
        perror("scandir");
    else {
        while(n--) {
            printf("%d %s\n", n,pDen[n]->d_name);
            free(pDen[n]);
        }
    }
    */


}

