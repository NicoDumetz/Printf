/*
** EPITECH PROJECT, 2023
** opgzejpgzijozgpe
** File description:
** lzegougzoehi
*/
#include "../include/my_printf.h"

static void print_width(int *compt, int *list_flagscompt, char *str)
{
    int width = list_flagscompt[12];
    int char_print = 0;

    if (list_flagscompt[0] > 0) {
        char_print += 2;
    }
    if ( width < my_strlen(str) + char_print)
        return;
    for (int i = 0; i < width - (my_strlen(str) + char_print); i++) {
        my_putchar(' ');
        *compt += 1;
    }
    if (list_flagscompt[0] > 0) {
        my_putstr("0x");
        *compt += 2;
    }
}

static void print_width_o(int *compt, int *list_flagscompt, char *str)
{
    int width = list_flagscompt[12];
    int char_print = 0;

    if (list_flagscompt[0] > 0) {
        char_print += 1;
    }
    if ( width < my_strlen(str) + char_print)
        return;
    for (int i = 0; i < width - (my_strlen(str) + char_print); i++) {
        my_putchar(' ');
        *compt += 1;
    }
}

static void print_width_d(int *compt, int *list_flagscompt, char *str)
{
    int width = list_flagscompt[12];

    if ( width < my_strlen(str))
        return;
    for (int i = 0; i < width - my_strlen(str); i++) {
        my_putchar(' ');
        *compt += 1;
    }
    if (list_flagscompt[0] > 0) {
        my_putstr("0");
        *compt += 1;
    }
}

int print_oct(va_list list, int *compt, int *list_flagscompt)
{
    long nb;
    int precision = list_flagscompt[5];
    char *str;

    nb = check_int_u(list, list_flagscompt);
    if ( list_flagscompt[6] == 2)
        nb = (unsigned char)nb;
    if ( precision >= 0) {
        precision = list_flagscompt[0] > 0 ? precision - 1 : precision;
        str = my_put_convert_base_prec(nb, "01234567", precision);
    } else
        str = my_put_convert_base(nb, "01234567");
    print_width_o(compt, list_flagscompt, str);
    my_putstr(str);
    *compt += my_strlen(str);
    free(str);
    return 1;
}

int print_dec(va_list list, int *compt, int *list_flagscompt)
{
    long nb;
    int precision;
    char *str;

    nb = check_int_u(list, list_flagscompt);
    if ( list_flagscompt[6] == 2)
        nb = (unsigned char)nb;
    if ( list_flagscompt[5] >= 0) {
        precision = list_flagscompt[5];
        str = my_put_convert_base_prec(nb, "0123456789", precision);
    } else
        str = my_put_convert_base(nb, "0123456789");
    print_width_d(compt, list_flagscompt, str);
    my_putstr(str);
    *compt += my_strlen(str);
    free(str);
    return 1;
}

int print_hex(va_list list, int *compt, int *list_flagscompt)
{
    long nb;
    int precision = 0;
    char *str;

    nb = check_int_u(list, list_flagscompt);
    if ( list_flagscompt[6] == 2)
        nb = (unsigned char)nb;
    if ( list_flagscompt[5] >= 0) {
        precision = list_flagscompt[5];
        str = my_put_convert_base_prec(nb, "0123456789abcdef", precision);
    } else
        str = my_put_convert_base(nb, "0123456789abcdef");
    print_width(compt, list_flagscompt, str);
    my_putstr(str);
    *compt += my_strlen(str);
    free(str);
    return 1;
}

int print_hex_maj(va_list list, int *compt, int *list_flagscompt)
{
    int nb;
    int precision;
    char *str;

    nb = check_int_u(list, list_flagscompt);
    if ( list_flagscompt[6] == 2)
        nb = (unsigned char)nb;
    if ( list_flagscompt[5] >= 0) {
        precision = list_flagscompt[5];
        str = my_put_convert_base_prec(nb, "0123456789ABCDEF", precision);
    } else
        str = my_put_convert_base(nb, "0123456789ABCDEF");
    print_width(compt, list_flagscompt, str);
    my_putstr(str);
    *compt += my_strlen(str);
    free(str);
    return 1;
}
