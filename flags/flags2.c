/*
** EPITECH PROJECT, 2023
** opgzejpgzijozgpe
** File description:
** lzegougzoehi
*/
#include "../include/my_printf.h"

int print_int(va_list list, int *compt, int *list_flagscompt)
{
    int nb;
    int precision;

    nb = va_arg(list, int);
    if (list_flagscompt[4] > 0 && nb > 0) {
        my_putchar('+');
        *compt += 1;
    } else if ( list_flagscompt[3] > 0) {
        my_putchar(' ');
        *compt += 1;
    }
    if ( list_flagscompt[5] > my_intlen(nb)) {
        precision = list_flagscompt[5];
        my_putnbr_prec(nb, precision);
        *compt += precision;
    } else {
        my_put_nbr(nb);
        *compt += my_intlen(nb);
    }
    return 1;
}

int print_oct(va_list list, int *compt, int *list_flagscompt)
{
    int nb;
    int precision;

    if (list_flagscompt[0] > 0) {
        my_putstr("0");
        *compt += 1;
    }
    nb = va_arg(list, int);
    if ( list_flagscompt[5] >= 0) {
        precision = list_flagscompt[5];
        *compt += my_put_convert_base_prec(nb, "01234567", precision);
    } else
        *compt += my_put_convert_base(nb, "01234567");
    return 1;
}

int print_dec(va_list list, int *compt, int *list_flagscompt)
{
    int nb;
    int precision;

    nb = va_arg(list, int);
    if ( list_flagscompt[5] >= 0) {
        precision = list_flagscompt[5];
        *compt += my_put_convert_base_prec(nb, "0123456789", precision);
    } else
        *compt += my_put_convert_base(nb, "0123456789");
    return 1;
}

int print_hex(va_list list, int *compt, int *list_flagscompt)
{
    int nb;
    int precision;

    if (list_flagscompt[0] > 0) {
        my_putstr("0x");
        *compt += 2;
    }
    nb = va_arg(list, int);
    if ( list_flagscompt[5] >= 0) {
        precision = list_flagscompt[5];
        *compt += my_put_convert_base_prec(nb, "0123456789abcdef", precision);
    } else
        *compt += my_put_convert_base(nb, "0123456789abcdef");
    return 1;
}

int print_hex_maj(va_list list, int *compt, int *list_flagscompt)
{
    int nb;
    int precision;

    if (list_flagscompt[0] > 0) {
        my_putstr("0X");
        *compt += 2;
    }
    nb = va_arg(list, int);
    if ( list_flagscompt[5] >= 0) {
        precision = list_flagscompt[5];
        *compt += my_put_convert_base_prec(nb, "0123456789ABCDEF", precision);
    } else
        *compt += my_put_convert_base(nb, "0123456789ABCDEF");
    return 1;
}
