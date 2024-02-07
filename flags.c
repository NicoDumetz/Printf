/*
** EPITECH PROJECT, 2023
** pogjepge
** File description:
** zgpihzgpizg
*/
#include "include/mini_printf.h"

int print_int(va_list list, int *compt)
{
    int nb;

    nb = va_arg(list, int);
    my_put_nbr(nb);
    *compt += my_intlen(nb);
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

int print_mod(va_list list, int *compt)
{
    my_putchar('%');
    *compt += 1;
    return 1;
}
