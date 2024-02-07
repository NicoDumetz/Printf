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
static const disp_t fonc_list[] = {
    {'d', &print_int},
    {'i', &print_int},
    {'s', &print_str},
    {'c', &print_char},
    {'%', &print_mod},
    {0, NULL}
};

#endif
