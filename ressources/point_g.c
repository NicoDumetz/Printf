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

static int put_nbr(double nb)
{
    if (nb < 0 && ABS(nb) < 1)
        my_putchar('-');
    return my_put_nbr((int)nb);
}

static int add_len_decimal(char *str, int counter)
{
    if (str[1]) {
        my_printf("%s", str);
        counter += my_strlen(str);
    }
    return counter;
}

static int float_type(double nb, double precision, double *marge)
{
    char *str;
    int counter = (nb < 0) ? 1 : 0;

    for (int k = 0; k < precision; k++)
        *marge /= 10;
    nb += (nb >= 0) ? *marge : -(*marge);
    counter += my_intlen(nb);
    nb += put_nbr(nb);
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
    return add_len_decimal(str, counter);
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
    while (!(nb >= 1 && nb < 10))
        nb *= mult;
    nb += marge;
    return precision_loop(nb, precision);
}

static int get_expos(double nb)
{
    double mult;
    int exp = 0;

    mult = (nb >= 1.0) ? 0.1 : 10.0;
    while (!(nb >= 1 && nb < 10)) {
        nb *= mult;
        exp += (mult < 1) ? 1 : -1;
    }
    return exp;
}

int point_g(double nb, int precision)
{
    double marge = 0.5;
    int exp;

    precision = (precision <= 0) ? 1 : precision;
    exp = get_expos(ABS(nb));
    if (ABS(nb) < 0.0001 || exp >= precision) {
        return my_put_sci_nbr(nb, 0, science_precision(nb, precision));
    } else {
        return float_type(nb, precision - exp - 1, &marge);
    }
}
