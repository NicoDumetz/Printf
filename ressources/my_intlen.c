/*
** EPITECH PROJECT, 2023
** oinevrzoinge
** File description:
** epkne oin be
*/
#include "my_printf.h"

int my_intlen(long nb)
{
    int compt = 0;

    if ( nb < 0 ) {
        nb = nb * -1;
        compt++;
    }
    if (nb == 0)
        return compt + 1;
    for (int i; nb > 0; i++) {
        compt++;
        nb /= 10;
    }
    return compt;
}
