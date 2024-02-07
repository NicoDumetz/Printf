/*
** EPITECH PROJECT, 2023
** oizhoihzge
** File description:
** zgoihzegoih
*/
#include "my_printf.h"
#include "../include/my_macro_abs.h"

static void is_negative(double *nb, double *marge)
{
    if (*nb < 0) {
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
        *marge /= 10;
        nb *= 10;
        str[k + 1] = ((int)nb % 10) + '0';
    }
    for (int k = precision; k >= 0 && str[k] == '0'; k--)
        str[k] = '\0';
    if (str[1])
        my_printf("%s", str);
    return 0;
}

static int precision_loop(double nb, int precision)
{
    char *str;

    str = malloc(precision);
    for (int k = 0; k < precision - 1; k++) {
        nb *= 10;
        str[k] = ((int)nb % 10) + '0';
    }
    for (int k = precision - 2; k >= 0; k--) {
        if (str[k] > '0' && str[k] <= '9')
            break;
        precision--;
    }
    return precision - 1;
}

static int science_precision(double nb, double precision)
{
    double mult;
    double marge = 0.5;

    for (int k = 0; k < precision - 1; k++)
        marge /= 10;
    nb = (nb < 0.0) ? -nb : nb;
    mult = (nb >= 1) ? 0.1 : 10.0;
    while (my_intlen(nb) != 1)
        nb *= mult;
    nb += marge;
    return precision_loop(nb, precision);
}

int point_g(double nb)
{
    int precision = 0;
    double marge = 0.5;

    if (my_intlen(ABS(nb)) <= precision && ABS(nb) > 0.0001) {
        float_type(nb, precision, &marge);
    } else {
        my_put_sci_nbr(nb, 0, science_precision(nb, precision));
    }
    return 0;
}
