/*
** EPITECH PROJECT, 2023
** MY STRLEN
** File description:
** Write a function that counts and returns the number
** of characters found in the string passed as parameter.
** It must be prototyped as follows
*/
#include "include/mini_printf.h"

int my_strlen(char const *str)
{
    int index;
    int compt;

    compt = 0;
    for ( index = 0; str[index] != '\0'; index++) {
        compt++;
    }
    return compt;
}
