
/*
** EPITECH PROJECT, 2023
** opgzejpgzijozgpe
** File description:
** lzegougzoehi
*/
#include "../include/my_printf.h"

int print_int(va_list list, int *compt)
{
    int nb;

    nb = va_arg(list, int);
    my_put_nbr(nb);
    *compt += my_intlen(nb);
    return 1;
}

int print_oct(va_list list, int *compt)
{
    int nb;

    nb = va_arg(list, int);
    *compt += my_put_convert_base(nb, "01234567");
    return 1;
}

int print_dec(va_list list, int *compt)
{
    int nb;

    nb = va_arg(list, int);
    *compt += my_put_convert_base(nb, "0123456789");
    return 1;
}

int print_hex(va_list list, int *compt)
{
    int nb;

    nb = va_arg(list, int);
    *compt += my_put_convert_base(nb, "0123456789abcdef");
    return 1;
}

int print_hex_maj(va_list list, int *compt)
{
    int nb;

    nb = va_arg(list, int);
    *compt += my_put_convert_base(nb, "0123456789ABCDEF");
    return 1;
}
