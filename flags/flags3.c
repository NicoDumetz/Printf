/*
** EPITECH PROJECT, 2023
** flags3
** File description:
** flags3 file
*/
#include "../include/my_printf.h"

static void print_width_e(int *compt, int *list_flagscompt, long double nb,
    int char_print)
{
    int width = list_flagscompt[12];

    if (list_flagscompt[4] > 0 && nb > 0) {
        char_print++;
    } else if ( list_flagscompt[3] > 0 && nb > 0)
        char_print++;
    if ( width < my_intlen(nb) + char_print + 1)
        return;
    for (int i = 0; i < width - (my_intlen(nb) + char_print + 4); i++) {
        my_putchar(' ');
        *compt += 1;
    }
}

int print_science_lowercase(va_list list, int *compt, int *list_flagscompt)
{
    long double nb;
    int precision = 6;
    int char_print;

    nb = check_float(list, list_flagscompt);
    if ( list_flagscompt[5] > 0)
        precision = list_flagscompt[5];
    char_print = precision;
    print_width_e(compt, list_flagscompt, nb, char_print);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += my_put_sci_nbr(nb, 0, precision);
    return 1;
}

int print_science_uppercase(va_list list, int *compt, int *list_flagscompt)
{
    long double nb;
    int precision = 6;
    int char_print;

    nb = check_float(list, list_flagscompt);
    if ( list_flagscompt[5] > 0)
        precision = list_flagscompt[5];
    char_print = precision;
    print_width_e(compt, list_flagscompt, nb, char_print);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += my_put_sci_nbr(nb, 1, precision);
    return 1;
}

static void width_adresse(int *compt, char *str, int precision,
    int *list_flagscompt)
{
    int width = list_flagscompt[12];

    if ( width < my_strlen(str) + precision + 2)
        return;
    for (int i = 0; i < width - (precision + 2); i++) {
        my_putchar(' ');
        *compt += 1;
    }
}

int print_adresse(va_list list, int *compt, int *list_flagscompt)
{
    unsigned long long nb;
    char *str;
    int precision = list_flagscompt[5] >= 0 ? list_flagscompt[5] : 0;

    nb = va_arg(list, unsigned long long);
    str = my_put_convert_base_ptr(nb, "0123456789abcdef");
    width_adresse(compt, str, precision, list_flagscompt);
    my_putstr("0x");
    *compt += 2;
    if ( precision > my_strlen(str)) {
        for (int i = 0; i < precision - my_strlen(str); i++ ) {
            my_putchar('0');
            *compt += 1;
        }
    }
    my_putstr(str);
    *compt += my_strlen(str);
    return 1;
}

int print_compt(va_list list, int *compt, int *list_flagscompt)
{
    int *var;

    var = va_arg(list, int *);
    *var = *compt;
    return 1;
}
