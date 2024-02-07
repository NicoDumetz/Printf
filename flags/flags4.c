/*
** EPITECH PROJECT, 2023
** ihzgeihpgz
** File description:
** lzfjbzgeli zihmgz ln
*/
#include "../include/my_printf.h"

int print_g_maj(va_list list, int *compt, int *list_flagscompt)
{
    int precision = 6;
    double nb = va_arg(list, double);

    nb = check_float(nb, list_flagscompt);
    if ( list_flagscompt[5] >= 0)
        precision = list_flagscompt[5];
    *compt += point_g(nb, precision, 1);
    return 1;
}
