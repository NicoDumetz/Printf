/*
** EPITECH PROJECT, 2023
** iihgepiojgzpeoj
** File description:
** gizehogze ihzg oi
*/
#include "../include/my_printf.h"


static void check_flags_int(long nb, int *compt, int *list_flagscompt)
{
    if (list_flagscompt[4] > 0 && nb > 0) {
        my_putchar('+');
        *compt += 1;
    } else if ( list_flagscompt[3] > 0 && nb > 0) {
        my_putchar(' ');
        *compt += 1;
    }
}

static void print_width_int(long nb, int char_print, int *compt
    , int *list_flagscompt)
{
    int width = list_flagscompt[12];

    char_print = nb < 0 ? char_print + 1 : char_print;
    if (list_flagscompt[4] > 0 && nb > 0) {
        char_print++;
    } else if ( list_flagscompt[3] > 0 && nb > 0)
        char_print++;
    if ( width < my_intlen(nb) + char_print)
        return;
    for (int i = 0; i < width - (my_intlen(nb) + char_print); i++) {
        my_putchar(' ');
        *compt += 1;
    }
}

int print_int(va_list list, int *compt, int *list_flagscompt)
{
    long nb;
    int precision;

    nb = check_int(list, list_flagscompt);
    if ( list_flagscompt[6] == 2)
        nb = (char)nb;
    if ( list_flagscompt[5] > my_intlen(nb)) {
        precision = list_flagscompt[5];
        print_width_int(nb, precision - my_intlen(nb), compt, list_flagscompt);
        check_flags_int(nb, compt, list_flagscompt);
        my_putnbr_prec(nb, precision);
        *compt = nb < 0 ? *compt + precision + 1 : *compt + precision;
    } else {
        print_width_int(nb, 0, compt, list_flagscompt);
        check_flags_int(nb, compt, list_flagscompt);
        my_put_nbr(nb);
        *compt += my_intlen(nb);
    }
    return 1;
}
