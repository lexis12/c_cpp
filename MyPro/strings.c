//
// Created by alex on 01.10.2019.
//


#include <malloc.h>
#include "strings.h"



int str_add(String *str, char *add) {

    int add_len = (int)strlen(add);
    int old_len = str->count;


        str->text = (char*) realloc (str->text,(str->count) + sizeof(char)* (add_len + 1));  //+1 = '\0'
        if (str->text == NULL) {
            printf("failed allocate memory");
            return 1;
        } else printf("mem allocated\n");



    str->count += add_len;
    int snprintf_res = snprintf(str->text + old_len, add_len + 1, "%s", add);  //+1 = '\0'
    if (snprintf_res == 0) {
        printf("failed to copy string");
    }

    return 0;

}

int str_clear (String *str){

    str->count = 0;
    //free(str->text);
    printf("mem free\n");

    return 0;
}