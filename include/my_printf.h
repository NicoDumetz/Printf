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
int my_put_sci_nbr(float nb);
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
    {'e', &print_science},
    {0, NULL}
};

#endif
