/*
** EPITECH PROJECT, 2023
** my_put_sci_nbr
** File description:
** display the given int in th scientific way
*/
#include "../../include/my_printf.h"

static void printer(float nb, int nb_mult)
{
    int counter = 1;

    counter += my_put_float(nb, 6);
    my_putchar('e');
    if (nb_mult >= 0) {
        my_putchar('+');
        counter++;
    }
    counter += my_put_nbr(nb_mult);
    return counter;
}

void my_put_sci_nbr(float nb)
{
    int neg;
    int neg_puiss;
    float mult;
    int nb_mult = 0;

    if (nb == 0.0)
        return printer(0, 0);
    neg = (nb < 0) ? 1 : 0;
    nb = (nb < 0) ? -nb : nb;
    mult = (nb >= 1) ? 0.1 : 10.0;
    while (!(nb >= 1 && nb < 10)) {
        nb = nb * mult;
        nb_mult += (mult > 1) ? -1 : 1;
    }
    return printer(nb, nb_mult);
}
