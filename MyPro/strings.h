//
// Created by alex on 01.10.2019.
//

#ifndef MYPRO_STRINGS_H
#define MYPRO_STRINGS_H

#endif //MYPRO_STRINGS_H


typedef struct string {
    int count;
    char *text;
}String;

int str_add (String *str, char *add);
int str_clear (String *str);