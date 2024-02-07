/*
** EPITECH PROJECT, 2023
** oizhoihzge
** File description:
** zgoihzegoih
*/
#include "my_printf.h"

static void is_negative(double *nb, double *marge)
{
    if ( *nb < 0) {
        *nb *= -1;
        *nb += *marge;
    }
}

static int float_type(double nb, double precision, double *marge)
{
    char *str;
    
    precision -= my_intlen(nb);
    for (int k = 0; k < precision; k++)
        *marge /= 10;
    nb += *marge;
    nb += my_put_nbr(nb);
    is_negative(&nb, marge);
    str = malloc(precision + 1);
    str[0] = '.';
    for (int k = 0; k < precision; k++) {
        nb *= 10;
        str[k + 1] = ((int)nb % 10) + '0';
    }
    for (int k = precision; k >= 0 && str[k] == '0'; k--)
        str[k] = '\0';
    if (str[1])
        my_printf("%s", str);
    return 0;
}

static int science_type(double nb, double precision, double *marge)
{
    for ( int k = 0; my_intlen(nb) != 1; k++) {
        nb /= 10;
    }
    float_type(nb, precision, marge);
    return 0;
}

int point_g(double nb)
{
    int precision = 6;
    double marge = 0.5;

    if ( my_intlen(nb) <= precision) {
        float_type(nb, precision, &marge);
    } else {
        science_type(nb, precision, &marge);
    }
    return 0;
}
