/*
** EPITECH PROJECT, 2023
** putchar
** File description:
** mojosglknldndl
*/
#include "include/mini_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
