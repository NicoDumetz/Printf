/*
** EPITECH PROJECT, 2023
** mini-printf
** File description:
** pz gog pio,"pgo po"'g
*/
#include "include/mini_printf.h"

int print(char c, va_list list, int *compt)
{
    for ( int j = 0; fonc_list[j].c; j++) {
        if (c == fonc_list[j].c)
            fonc_list[j].f(list, compt);
    }
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int compt = 0;

    va_start(list, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%')
            print(format[++i], list, &compt);
        else
            compt += write(1, format + i, 1);
    }
    va_end(list);
    return compt;
}
