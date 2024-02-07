/*
** EPITECH PROJECT, 2023
** ihzgeihpgz
** File description:
** lzfjbzgeli zihmgz ln
*/
#include "../include/my_printf.h"

static void print_width(int *compt, int *list_flagscompt, long double nb,
    int char_print)
{
    int width = list_flagscompt[12];
    int zero = list_flagscompt[1] > 0 && list_flagscompt[2] == 0 ? '0' : ' ';

    if (list_flagscompt[4] > 0 && nb > 0) {
        char_print++;
    } else if ( list_flagscompt[3] > 0 && nb > 0)
        char_print++;
    if ( width < my_intlen(nb) + char_print + 1)
        return;
    for (int i = 0; i < width - (my_intlen(nb) + char_print + 3); i++) {
        my_putchar(zero);
        *compt += 1;
    }
}

int print_g(va_list list, int *compt, int *list_flagscompt)
{
    int precision = 6;
    long double nb;
    int char_print = 0;

    nb = check_float(list, list_flagscompt);
    if ( list_flagscompt[5] >= 0)
        precision = list_flagscompt[5];
    if ( list_flagscompt[2] == 0)
        print_width(compt, list_flagscompt, nb, char_print);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += point_g(nb, precision, 0);
    if ( list_flagscompt[2] > 0)
        print_width(compt, list_flagscompt, nb, char_print);
    return 1;
}

int print_g_maj(va_list list, int *compt, int *list_flagscompt)
{
    int precision = 6;
    double nb;
    int char_print = 0;

    nb = check_float(list, list_flagscompt);
    if ( list_flagscompt[5] >= 0)
        precision = list_flagscompt[5];
    if ( list_flagscompt[2] == 0)
        print_width(compt, list_flagscompt, nb, char_print);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += point_g(nb, precision, 1);
    if ( list_flagscompt[2] > 0)
        print_width(compt, list_flagscompt, nb, char_print);
    return 1;
}
