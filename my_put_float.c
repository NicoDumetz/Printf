/*
** EPITECH PROJECT, 2023
** pojgzejpgz
** File description:
** zeogihzgohi
*/
#include "include/my_printf.h"

int my_put_float(double nb, int precision)
{
    double marge = 0.5;
    int power = 1;

    for (int k = 0; k <= precision; k++) {
	power *= 10;
    }
    marge /= power;
    nb -= my_put_nbr(nb);
    my_putchar('.');
    nb += marge;
    for (int index = 0; index < precision; index++) {
        nb *= 10;
        nb -= my_put_nbr(nb);
    }
}
