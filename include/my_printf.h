/*
** EPITECH PROJECT, 2023
** oinoniz
** File description:
** gpipng"ip
*/

#ifndef MY_PRINTF
    #define MY_PRINTF
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdint.h>
typedef int(*fonc)();
typedef struct disp {
    char c;
    fonc f;
} disp_t;
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_intlen(int nb);
int print_int(va_list list, int *compt);
int print_char(va_list list, int *compt);
int print_str(va_list list, int *compt);
int print_mod(va_list list, int *compt);
int my_printf(const char *format, ...);
int my_put_float(double nb, int precision);
int print_float(va_list list, int *compt);
int my_put_convert_base(unsigned int nb, char *base);
int print_oct(va_list list, int *compt);
int print_dec(va_list list, int *compt);
int print_hex(va_list list, int *compt);
int print_hex_maj(va_list list, int *compt);
int print_science(va_list list, int *compt);
int my_put_sci_nbr(double nb, int upper);
int print_hex(va_list list, int *compt);
int print_adresse(va_list list, int *compt);
int my_put_convert_base_ptr(unsigned long long nb, char *base);
int print_science_lowercase(va_list list, int *compt);
int print_science_uppercase(va_list list, int *compt);
static const disp_t fonc_list[] = {
    {'d', &print_int},
    {'i', &print_int},
    {'s', &print_str},
    {'c', &print_char},
    {'%', &print_mod},
    {'f', &print_float},
    {'o', &print_oct},
    {'u', &print_dec},
    {'x', &print_hex},
    {'X', &print_hex_maj},
    {'e', &print_science_lowercase},
    {'E', &print_science_uppercase},
    {'p', &print_adresse},
    {0, NULL}
};

#endif
