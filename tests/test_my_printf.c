/*
** EPITECH PROJECT, 2023
** test_my_printf
** File description:
** serie of test for my_printf
*/

#include "test.h"

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

Test(specificteur_o, normal_value, .init = redirect_all_stdout)
{
    my_printf("%o", 123456789);
    cr_assert_stdout_eq_str("726746425");
}

Test(specificateur_o, null_value, .init = redirect_all_stdout)
{
    my_printf("%o", 0);
    cr_assert_stdout_eq_str("0");
}

Test(specificateur_u, normal_value, .init = redirect_all_stdout)
{
    my_printf("%u", 123456789);
    cr_assert_stdout_eq_str("123456789");
}

Test(specificateur_u, null_value, .init = redirect_all_stdout)
{
    my_printf("%u", 0);
    cr_assert_stdout_eq_str("0");
}

Test(specificateur_x, normal_value, .init = redirect_all_stdout)
{
    my_printf("%x", 123456789);
    cr_assert_stdout_eq_str("75bcd15");
}

Test(specificateur_X, normal_value, .init = redirect_all_stdout)
{
    my_printf("%X", 123456789);
    cr_assert_stdout_eq_str("75BCD15");
}

Test(specificateur_x, null_value, .init = redirect_all_stdout)
{
    my_printf("%x", 0);
    cr_assert_stdout_eq_str("0");
}

Test(specificateur_e, negative_value_positive_expos, .init = redirect_all_stdout)
{
    my_printf("%e", -123456789.0);
    cr_assert_stdout_eq_str("-1.234568e+08");
}

Test(specificateur_e, negative_value_negative_expos, .init = redirect_all_stdout)
{
    my_printf("%e", -0.123456789);
    cr_assert_stdout_eq_str("-1.234568e-01");
}

Test(specificateur_e, null_value, .init = redirect_all_stdout)
{
    my_printf("%e", 0.0);
    cr_assert_stdout_eq_str("0.000000e+00");
}

Test(specificateur_e, positive_value_positive_expos, .init = redirect_all_stdout)
{
    my_printf("%e", 123456789.0);
    cr_assert_stdout_eq_str("1.234568e+08");
}

Test(specificateur_e, positive_value_null_expos, .init = redirect_all_stdout)
{
    my_printf("%e", 1.234567);
    cr_assert_stdout_eq_str("1.234567e+00");
}

Test(specificateur_e, positive_value_negative_expos, .init = redirect_all_stdout)
{
    my_printf("%e", 0.123);
    cr_assert_stdout_eq_str("1.230000e-01");
}

Test(specificateur_E, random_test, .init = redirect_all_stdout)
{
    my_printf("%E", 123.0);
    cr_assert_stdout_eq_str("1.230000E+02");
}

Test(specificateur_n, null_test, .init = redirect_all_stdout)
{
    int c;
    my_printf("%n feur", &c);
    cr_assert(c == 0);
}

Test(specificateur_n, normal_value, .init = redirect_all_stdout)
{
    int c;
    my_printf("Mmmmh bananes %n", &c);
    cr_assert(c == 14);
}

Test(specificateur_g, negative_float_without_0, .init = redirect_all_stdout)
{
    my_printf("%g", -123.4567);
    cr_assert_stdout_eq_str("-123.457");
}

Test(specificateur_g, negative_float_with_0, .init = redirect_all_stdout)
{
    my_printf("%g", -0.1234999);
    cr_assert_stdout_eq_str("-0.1235");
}

Test(specificateur_g, positive_float, .init = redirect_all_stdout)
{
    my_printf("%g", 123.4564);
    cr_assert_stdout_eq_str("123.456");
}
