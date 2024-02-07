/*
** EPITECH PROJECT, 2023
** pojgzejpgz
** File description:
** zeogihzgohi
*/
#include "my_printf.h"

static void is_negative(double *nb, int *compt)
{
    if (*nb < 0) {
        *nb *= -1;
        my_putchar('-');
        *compt += 1;
    }
}

int my_put_float(double nb, int precision)
{
    double marge = 0.5;
    int compt = my_intlen(nb);

    is_negative(&nb, &compt);
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
