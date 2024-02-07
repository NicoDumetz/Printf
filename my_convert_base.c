/*
** EPITECH PROJECT, 2023
** lzieghlegn
** File description:
** lzjegloizelgein nzmo gzpmogz
*/
#include "include/my_printf.h"

static char *my_revstr_convert(char *str)
{
    int index;
    int len = my_strlen(str) - 1;
    char temp;

    for ( index = 0; index < len; index++) {
        temp = str[index];
        str[index] = str[len];
        str[len] = temp;
        len--;
    }
    return str;
}

int my_put_convert_base(unsigned int nb, char *base)
{
    int len = my_strlen(base);
    char res[300000];
    int index = 0;

    for (index; nb > 0; index++) {
        res[index] = base[nb % len];
        nb /= len;
    }
    res[index] = '\0';
    my_revstr_convert(res);
    my_putstr(res);
    return my_strlen(res);
}
