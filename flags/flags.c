/*
** EPITECH PROJECT, 2023
** flags list1
** File description:
** list of function used by my_printf
** that initialize variable to execute asked specification
*/
#include "../include/my_printf.h"

int print_float(va_list list, int *compt, int *list_flagscompt)
{
    double nb;

    nb = va_arg(list, double);
    if (list_flagscompt[4] > 0 && nb > 0) {
        my_putchar('+');
        *compt += 1;
    } else if ( list_flagscompt[3] > 0) {
        my_putchar(' ');
        *compt += 1;
    }
    *compt += my_put_float(nb, 6);
    return 1;
}

int print_char(va_list list, int *compt, int *list_flagscompt)
{
    my_putchar(va_arg(list, int));
    *compt += 1;
    return 1;
}

int print_str(va_list list, int *compt, int *list_flagscompt)
{
    char *str;

    str = va_arg(list, char *);
    my_putstr(str);
    *compt += my_strlen(str);
    return 1;
}

int print_mod(va_list list, int *compt, int *list_flagscompt)
{
    my_putchar('%');
    *compt += 1;
    return 1;
}
