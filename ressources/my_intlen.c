/*
** EPITECH PROJECT, 2023
** oinevrzoinge
** File description:
** epkne oin be
*/
#include "my_printf.h"

int my_intlen(int nb)
{
    int compt = 0;

    if ( nb < 0 ) {
        compt++;
        nb = nb * -1;
    }
    for (int i; nb > 0; i++) {
        compt++;
        nb /= 10;
    }
    return compt;
}
