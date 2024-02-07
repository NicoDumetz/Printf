/*
** EPITECH PROJECT, 2023
** flags3
** File description:
** flags3 file
*/
#include "../include/my_printf.h"

int print_science(va_list list, int *compt)
{
    *compt += my_put_sci_nbr(va_arg(list, double));
    return 1;
}
