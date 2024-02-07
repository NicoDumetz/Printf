/*
** EPITECH PROJECT, 2023
** pojgzejpgz
** File description:
** zeogihzgohi
*/
#include "my_printf.h"

int my_put_float(double nb, int precision)
{
    double marge = 0.5;
    int compt = my_intlen(nb);

    for (int k = 0; k < precision; k++) {
        marge /= 10;
    }
    nb -= my_put_nbr(nb);
    my_putchar('.');
    compt++;
    nb += marge;
    for (int index = 0; index < precision; index++) {
        nb *= 10;
        nb -= my_put_nbr(nb);
        compt++;
    }
    return compt;
}
