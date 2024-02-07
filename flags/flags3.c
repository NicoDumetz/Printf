/*
** EPITECH PROJECT, 2023
** flags3
** File description:
** flags3 file
*/
#include "../include/my_printf.h"

int print_science_lowercase(va_list list, int *compt)
{
    *compt += my_put_sci_nbr(va_arg(list, double), 0);
    return 1;
}

int print_science_uppercase(va_list list, int *compt)
{
    *compt += my_put_sci_nbr(va_arg(list, double), 1);
    return 1;
}

int print_adresse(va_list list, int *compt)
{
    unsigned long long nb;

    my_putstr("0x");
    *compt += 2;
    nb = va_arg(list, unsigned long long);
    *compt += my_put_convert_base_ptr(nb, "0123456789abcdef");
    return 1;
}

int print_compt(va_list list, int *compt)
{
    int *var;

    var = va_arg(list, int *);
    *var = *compt;
    return 1;
}
