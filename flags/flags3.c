
/*
** EPITECH PROJECT, 2023
** flags3
** File description:
** flags3 file
*/
#include "../include/my_printf.h"
#include "string.h"

int print_science(va_list list, int *compt)
{
    *compt += my_put_sci_nbr(va_arg(list, double));
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
