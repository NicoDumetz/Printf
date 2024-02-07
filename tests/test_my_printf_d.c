/*
** EPITECH PROJECT, 2023
** test_my_printf_d
** File description:
** unit tests for d specifier
*/

#include "test.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(specificateur_d, negative_value, .init = redirect_all_stdout)
{
    my_printf("J'ai une dette de %d bananes", -123456789);
    cr_assert_stdout_eq_str("J'ai une dette de -123456789 bananes");
}

Test(specificateur_d, null_value, .init = redirect_all_stdout)
{
    my_printf("Il me reste %d bananes", 0);
    cr_assert_stdout_eq_str("Il me reste 0 bananes");
}

Test(specificateur_d, positive_value, .init = redirect_all_stdout)
{
    my_printf("Je me suis acheté %d bananes", 123456789);
    cr_assert_stdout_eq_str("Je me suis acheté 123456789 bananes");
}

Test(specificateur_d, return_value, .init = redirect_all_stdout)
{
    cr_assert(my_printf("J'ai %d bananes", 14000) == 18);
}
