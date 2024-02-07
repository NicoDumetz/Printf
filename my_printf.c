/*
** EPITECH PROJECT, 2023
** mini-printf
** File description:
** pz gog pio,"pgo po"'g
*/
#include "include/my_printf.h"

void print(const char *format, va_list list, int *compt, int *i)
{
    int list_flagscompt[] = { 0, 0, 0, 0, 0, -1, 0};

    for ( int j = 0; list_flags[j]; j++) {
        if (format[*i] == list_flags[j]) {
            list_flagscompt[j] += 1;
            *i += 1;
            j = 0;
        }
    }
    if ( format[*i] == '.') {
        *i += 1;
        list_flagscompt[5] = my_getnbr(format + *i);
        if (list_flagscompt[5] != 0)
            *i += my_intlen(list_flagscompt[5]);
    }
    for ( int j = 0; fonc_list[j].c; j++) {
        if (format[*i] == fonc_list[j].c)
            fonc_list[j].f(list, compt, list_flagscompt);
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int compt = 0;
    int i;

    va_start(list, format);
    for (i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            i++;
            print(format, list, &compt, &i);
        } else
            compt += write(1, format + i, 1);
    }
    va_end(list);
    return compt;
}
