/*
** EPITECH PROJECT, 2023
** flags list1
** File description:
** list of function used by my_printf
** that initialize variable to execute asked specification
*/
#include "../include/my_printf.h"

int print_float(va_list list, int *compt)
{
    double nb;

    nb = va_arg(list, double);
    *compt += my_put_float(nb, 6);
    return 1;
}

int print_char(va_list list, int *compt)
{
    my_putchar(va_arg(list, int));
    *compt += 1;
    return 1;
}

int print_str(va_list list, int *compt)
{
    char *str;

    str = va_arg(list, char *);
    my_putstr(str);
    *compt += my_strlen(str);
    return 1;
}

int print_mod(__attribute__((unused)) va_list list, int *compt)
{
    my_putchar('%');
    *compt += 1;
    return 1;
}
