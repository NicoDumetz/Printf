/*
** EPITECH PROJECT, 2023
** test.h
** File description:
** header for redirect_all_stdout
*/

#ifndef TEST_HEADER
    #define TEST_HEADER
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_printf(const char *format, ...);
void redirect_all_stdout(void);
#endif
