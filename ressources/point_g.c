/*
** EPITECH PROJECT, 2023
** oizhoihzge
** File description:
** zgoihzegoih
*/
#include "my_printf.h"

int point_g(double nb)
{
    int precision = 6;
    char str[7];
    int index;
    
    if ( my_intlen(nb) <= precision) {
        precision -= my_intlen(nb);
        for (index = 0; index < precision; index++) {
            nb *= 10;
        }
        for (; index > 0; index--) {
            nb /=10;
        }
        my_put_float(nb, precision);
    }
    return 0;
}
