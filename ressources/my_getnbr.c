/*
** EPITECH PROJECT, 2023
** MY GETNBR
** File description:
** Write a function that returns a number, sent to
** the function as a string. It must be prototyped as follows:
*/
#include "my_printf.h"

static int verify_max(int res, int sign)
{
    res *= sign;
    if ( res <= -2147483648 || res >= 2147483648 )
        return 0;
    return res;
}

static int varsign(int sign, char const *str, int i)
{
    if ((str[i] == '+' && sign > 0) || (str[i] == '-' && sign < 0)) {
        sign *= 1;
    } else {
        sign *= -1;
    }
    return sign;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    long res = 0;

    if (str[0] < 42 || str[0] > 59 )
        return 0;
    while ( str[i] == '+' || str[i] == '-' ) {
        sign = varsign(sign, str, i);
        i++;
    }
    res += str[i] - 48;
    i++;
    while ( str[i] >= 48 && str[i] <= 57 ) {
        res *= 10;
        res += str[i] - 48;
        i++;
        if ( res <= -2147483648 || res >= 2147483648 )
            return 0;
    }
    return verify_max(res, sign);
}
