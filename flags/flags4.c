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

    if (list_flagscompt[4] > 0 && nb > 0) {
        char_print++;
    } else if ( list_flagscompt[3] > 0 && nb > 0)
        char_print++;
    if ( width < my_intlen(nb) + char_print + 1)
        return;
    for (int i = 0; i < width - (my_intlen(nb) + char_print + 2); i++) {
        my_putchar(' ');
        *compt += 1;
    }
}

int print_g(va_list list, int *compt, int *list_flagscompt)
{
    int precision = 6;
    double nb = va_arg(list, double);
    int char_print = 0;

    nb = check_float(nb, list_flagscompt);
    if ( list_flagscompt[5] >= 0)
        precision = list_flagscompt[5];
    print_width(compt, list_flagscompt, nb, char_print);
    *compt += point_g(nb, precision, 0);
    return 1;
}

int print_g_maj(va_list list, int *compt, int *list_flagscompt)
{
    int precision = 6;
    double nb = va_arg(list, double);
    int char_print = 0;

    nb = check_float(nb, list_flagscompt);
    if ( list_flagscompt[5] >= 0)
        precision = list_flagscompt[5];
    print_width(compt, list_flagscompt, nb, char_print);
    *compt += point_g(nb, precision, 1);
    return 1;
}
