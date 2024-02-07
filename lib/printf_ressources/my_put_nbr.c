/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** Write a function that displays the number given as
** a parameter. It must be able to display all the possible
** values of an int, and must be prototyped as follows
*/
#include "../../include/my_printf.h"

static int is_negative(int nb)
{
    if ( nb < 0 ) {
        my_putchar('-');
        nb = nb * -1;
    }
    return nb;
}

int my_put_nbr(int nb)
{
    long new_nb;

    if ( nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    nb = is_negative(nb);
    new_nb = nb;
    if ( new_nb <= 9 ) {
        my_putchar(new_nb + 48);
    } else {
        my_put_nbr(new_nb / 10);
        my_putchar(new_nb % 10 + 48);
    }
    return nb;
}
