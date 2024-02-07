/*
** EPITECH PROJECT, 2023
** lihzrhilgz
** File description:
** suvghosgh
*/
#include "my_printf.h"

char *my_strcat(char *dest, char const *src)
{
    int index;
    int len = my_strlen(dest);

    for ( index = 0; src[index]; index++) {
        dest[len] = src[index];
        len++;
    }
    dest[len] = '\0';
    return dest;
}
