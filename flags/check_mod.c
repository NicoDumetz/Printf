/*
** EPITECH PROJECT, 2023
** pgehigeh pongegpjeo
** File description:
** egpih eizhgpj pgjz pgj oz
*/
#include "../include/my_printf.h"

long check_int(int nb, int *list_flagscompt)
{
    if ( list_flagscompt[6] == 1)
        return (short int)nb;
    if ( list_flagscompt[6] == 2)
        return (char)nb;
    if ( list_flagscompt[7] == 1 || list_flagscompt[7] == 2)
        return (long)nb;
    if ( list_flagscompt[8] == 1)
        return (intmax_t)nb;
    if ( list_flagscompt[9] == 1)
        return (size_t)nb;
    if ( list_flagscompt[10] == 1)
        return (ptrdiff_t)nb;
    return (int)nb;
}

unsigned long check_int_u(int nb, int *list_flagscompt)
{
    if ( list_flagscompt[6] == 1)
        return (unsigned short int)nb;
    if ( list_flagscompt[6] == 2)
        return (unsigned char)nb;
    if ( list_flagscompt[7] == 1 || list_flagscompt[7] == 2)
        return (unsigned long)nb;
    if ( list_flagscompt[8] == 1)
        return (uintmax_t)nb;
    if ( list_flagscompt[9] == 1)
        return (size_t)nb;
    if ( list_flagscompt[10] == 1)
        return (ptrdiff_t)nb;
    return (unsigned int)nb;
}

long double check_float(double nb, int *list_flagscompt)
{
    if ( list_flagscompt[11] == 1)
        return (long double)nb;
    return (double)nb;
}
