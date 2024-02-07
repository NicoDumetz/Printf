/*
** EPITECH PROJECT, 2023
** mini-printf
** File description:
** pz gog pio,"pgo po"'g
*/

#include "include/mini_printf.h"

int print_2(char c, va_list list, int *compt)
{
    for ( int j = 0; fonc_list[j].c; j++)
        c == fonc_list[j].c ? fonc_list[j].f(list, compt) : 0;
}

int mini_printf_2(const char *format, ...)
{
    va_list list;
    int compt = 0;

    va_start(list, format);
    for (int i = 0; i < my_strlen(format); i++) {
        compt += format[i] == '%' ? print_2(format[++i], list, &compt), 0
	: write(1, format + i, 1);
    }
    return va_end(list), compt;
}
