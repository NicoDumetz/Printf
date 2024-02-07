/*
** EPITECH PROJECT, 2023
** MY_PUTSTR
** File description:
** Write a function that displays, one-by-one,
** the characters of a string.
** The address of the string’s first character will be found
** in the pointer passed as a parameter to the function,
** which must be prototyped as follows:
*/
#include "my_printf.h"

int my_putstr(char const *str)
{
    int index;

    for ( index = 0; str[index] != '\0'; index++) {
        my_putchar(str[index]);
    }
    return 0;
}

int my_putstr_prec(char const *str, int precision)
{
    int index;

    for ( index = 0; str[index] != '\0' && index < precision; index++) {
        my_putchar(str[index]);
    }
    return 0;
}
