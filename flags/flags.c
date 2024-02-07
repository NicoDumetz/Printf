/*
** EPITECH PROJECT, 2023
** flags list1
** File description:
** list of function used by my_printf
** that initialize variable to execute asked specification
*/
#include "../include/my_printf.h"

int print_char(va_list list, int *compt, int *list_flagscompt)
{
    int width = list_flagscompt[12];

    for (int i = 1; i < width; i++) {
        my_putchar(' ');
        *compt += 1;
    }
    my_putchar(va_arg(list, int));
    *compt += 1;
    return 1;
}

static void width_str(int len, int *compt, int *list_flagscompt)
{
    int width = list_flagscompt[12];

    if ( width < len)
        return;
    for (int i = 0; i < width - len; i++) {
        my_putchar(' ');
        *compt += 1;
    }
}

int print_str(va_list list, int *compt, int *list_flagscompt)
{
    char *str;
    int char_print;
    int precision = list_flagscompt[5];

    str = va_arg(list, char *);
    if ( precision > 0) {
        char_print = precision < my_strlen(str) ? precision : my_strlen(str);
        width_str(char_print, compt, list_flagscompt);
        my_putstr_prec(str, precision);
        if ( precision < my_strlen(str))
            *compt += precision;
        else
            *compt += my_strlen(str);
    } else {
        width_str(my_strlen(str), compt, list_flagscompt);
        my_putstr(str);
        *compt += my_strlen(str);
    }
    return 1;
}

int print_mod(va_list list, int *compt, int *list_flagscompt)
{
    my_putchar('%');
    *compt += 1;
    return 1;
}
