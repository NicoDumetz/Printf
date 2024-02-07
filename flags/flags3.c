/*
** EPITECH PROJECT, 2023
** flags3
** File description:
** flags3 file
*/
#include "../include/my_printf.h"

int print_science_lowercase(va_list list, int *compt, int *list_flagscompt)
{
    double nb = va_arg(list, double);
    int precision = 6;

    if (list_flagscompt[4] > 0 && nb > 0) {
        my_putchar('+');
        *compt += 1;
    } else if ( list_flagscompt[3] > 0) {
        my_putchar(' ');
        *compt += 1;
    }
    if ( list_flagscompt[5] > 0)
        precision = list_flagscompt[5];
    *compt += my_put_sci_nbr(nb, 0, precision);
    return 1;
}

int print_science_uppercase(va_list list, int *compt, int *list_flagscompt)
{
    double nb = va_arg(list, double);
    int precision = 6;

    if (list_flagscompt[4] > 0 && nb > 0) {
        my_putchar('+');
        *compt += 1;
    } else if ( list_flagscompt[3] > 0) {
        my_putchar(' ');
        *compt += 1;
    }
    if ( list_flagscompt[5] > 0)
        precision = list_flagscompt[5];
    *compt += my_put_sci_nbr(nb, 1, precision);
    return 1;
}

int print_adresse(va_list list, int *compt, int *list_flagscompt)
{
    unsigned long long nb;

    my_putstr("0x");
    *compt += 2;
    nb = va_arg(list, unsigned long long);
    *compt += my_put_convert_base_ptr(nb, "0123456789abcdef");
    return 1;
}

int print_compt(va_list list, int *compt, int *list_flagscompt)
{
    int *var;

    var = va_arg(list, int *);
    *var = *compt;
    return 1;
}

int print_g(va_list list, int *compt, int *list_flagscompt)
{
    point_g(va_arg(list, double));
    *compt += 1;
    return 1;
}
