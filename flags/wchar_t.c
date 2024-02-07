/*
** EPITECH PROJECT, 2023
** pgeopegoje
** File description:
** epr,,epg,o
*/

#include "../include/my_printf.h"

static int my_wcharlen(wchar_t const *str)
{
    int index;
    int compt;

    compt = 0;
    for ( index = 0; str[index] != '\0'; index++) {
        compt++;
    }
    return compt;
}

static int my_putwchar(wchar_t const *str)
{
    int index;

    for ( index = 0; str[index] != '\0'; index++) {
        my_putchar(str[index]);
    }
    return 0;
}

static int my_putstr_wchar(wchar_t const *str, int precision)
{
    int index;

    for ( index = 0; str[index] != '\0' && index < precision; index++) {
        my_putchar(str[index]);
    }
    return 0;
}

static void width_wchar(int len, int *compt, int *list_flagscompt)
{
    int width = list_flagscompt[12];
    int zero = ' ';

    if ( width < len)
        return;
    for (int i = 0; i < width - len; i++) {
        my_putchar(zero);
        *compt += 1;
    }
}

static int wchar_precision(int precision, wchar_t *str, int *compt,
    int *list_flagscompt)
{
    int char_print;

    char_print = precision < my_wcharlen(str) ? precision : my_wcharlen(str);
    if ( list_flagscompt[2] == 0)
        width_wchar(char_print, compt, list_flagscompt);
    my_putstr_wchar(str, precision);
    if ( list_flagscompt[2] > 0)
        width_wchar(char_print, compt, list_flagscompt);
    if ( precision < my_wcharlen(str))
        *compt += precision;
    else
        *compt += my_wcharlen(str);
}

int print_wchar(va_list list, int *compt, int *list_flagscompt)
{
    wchar_t *str;
    int precision = list_flagscompt[5];

    str = va_arg(list, wchar_t *);
    if ( precision > 0) {
        wchar_precision(precision, str, compt, list_flagscompt);
    } else {
        if ( list_flagscompt[2] == 0)
            width_wchar(my_wcharlen(str), compt, list_flagscompt);
	my_putwchar(str);
        if ( list_flagscompt[2] > 0)
            width_wchar(my_wcharlen(str), compt, list_flagscompt);
        *compt += my_wcharlen(str);
    }
    return 1;
}
