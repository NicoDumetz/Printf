/*
** EPITECH PROJECT, 2023
** lzieghlegn
** File description:
** lzjegloizelgein nzmo gzpmogz
*/
#include "my_printf.h"

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
    char res[30000];
    int index;

    for (index = 0; nb > 0; index++) {
        res[index] = base[nb % len];
        nb /= len;
    }
    res[index] = '\0';
    my_revstr_convert(res);
    my_putstr(res);
    return my_strlen(res);
}

int my_put_convert_base_ptr(unsigned long long nb, char *base)
{
    int len = my_strlen(base);
    char res[30000];
    int index;

    for (index = 0; nb > 0; index++) {
        res[index] = base[nb % len];
        nb /= len;
    }
    res[index] = '\0';
    my_revstr_convert(res);
    my_putstr(res);
    return my_strlen(res);
}

int my_put_convert_base_prec(unsigned int nb, char *base, int precision)
{
    int len = my_strlen(base);
    char res[30000];
    int index;
    int compt = 0;

    for (index = 0; nb > 0; index++) {
        res[index] = base[nb % len];
        nb /= len;
    }
    res[index] = '\0';
    my_revstr_convert(res);
    if ( precision > my_strlen(res)) {
        for (int i = 0 ; i < precision - my_strlen(res); i++) {
            my_putchar('0');
            compt++;
        }
    }
    my_putstr(res);
    return my_strlen(res) + compt;
}
