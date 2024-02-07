/*
** EPITECH PROJECT, 2023
** my_put_sci_nbr
** File description:
** display the given int in th scientific way
*/
#include "../../include/my_printf.h"

static int printer(double nb, int nb_mult, int upper)
{
    int counter = 1;

    counter += my_put_float(nb, 6);
    my_putchar((upper) ? 'E' : 'e');
    if (nb_mult >= 0) {
        my_putchar('+');
        counter++;
    }
    if (nb_mult <= 9)
        counter += my_put_nbr(0) + 1;
    my_put_nbr(nb_mult);
    counter += my_intlen(nb_mult);
    return counter;
}

int my_put_sci_nbr(double nb, int upper)
{
    int neg;
    double mult;
    int nb_mult = 0;

    if (nb == 0.0)
        return printer(0, 0, upper);
    neg = (nb < 0) ? 1 : 0;
    nb = (nb < 0) ? -nb : nb;
    mult = (nb >= 1) ? 0.1 : 10.0;
    while (!(nb >= 1 && nb < 10)) {
        nb = nb * mult;
        nb_mult += (mult > 1) ? -1 : 1;
    }
    nb = (neg) ? -nb : nb;
    return printer(nb, nb_mult, upper);
}
