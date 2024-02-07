/*
** EPITECH PROJECT, 2023
** test_my_printf_d
** File description:
** unit tests for d specifier
*/

#include "test.h"

Test(specificateur_d, negative_value, .init = redirect_all_stdout)
{
    my_printf("J'ai une dette de %d bananes", -123456789);
    cr_assert_stdout_eq_str("J'ai une dette de -123456789 bananes");
}

Test(specificateur_i, negative_value, .init = redirect_all_stdout)
{
    my_printf("J'ai une dette de %i bananes", -123456789);
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

Test(specificateur_d, positive_value_space, .init = redirect_all_stdout)
{
    my_printf("Je me suis acheté% d bananes", 123456789);
    cr_assert_stdout_eq_str("Je me suis acheté 123456789 bananes");
}

Test(specificateur_d, negative_value_space, .init = redirect_all_stdout)
{
    my_printf("Je suis endetté de %d bananes", -123456789);
    cr_assert_stdout_eq_str("Je suis endetté de -123456789 bananes");
}

Test(specificateur_d, positive_value_plus, .init = redirect_all_stdout)
{
    my_printf("Je me suis acheté %+d bananes", 123456789);
    cr_assert_stdout_eq_str("Je me suis acheté +123456789 bananes");
}

Test(specificateur_d, negative_value_plus, .init = redirect_all_stdout)
{
    my_printf("Je me suis acheté %+d bananes", -123456789);
    cr_assert_stdout_eq_str("Je me suis acheté -123456789 bananes");
}

Test(specificateur_d, modificateur_h, .init = redirect_all_stdout)
{
    my_printf("%hd", 123456789);
    cr_assert_stdout_eq_str("-13035");
}

Test(specificateur_d, modificateur_hh, .init = redirect_all_stdout)
{
    my_printf("%hhd", 123456789);
    cr_assert_stdout_eq_str("21");
}

Test(specificateur_d, modificateur_l, .init = redirect_all_stdout)
{
    my_printf("%ld", 123456789);
    cr_assert_stdout_eq_str("123456789");
}

Test(specificateur_d, modificateur_ll, .init = redirect_all_stdout)
{
    my_printf("%lld", 123456789);
    cr_assert_stdout_eq_str("123456789");
}

Test(specificateur_d, gabariz, .init = redirect_all_stdout)
{
    my_printf("%10d", 123456789);
    cr_assert_stdout_eq_str(" 123456789");
}

Test(specificateur_d, gabariz_minus, .init = redirect_all_stdout)
{
    my_printf("%-10d", 123456789);
    cr_assert_stdout_eq_str("123456789 ");
}

Test(specificateur_d, gabariz_zero, .init = redirect_all_stdout)
{
    my_printf("%010d", 123456789);
    cr_assert_stdout_eq_str("0123456789");
}

Test(specificateur_d, precision, .init = redirect_all_stdout)
{
    my_printf("%.10d", 123456789);
    cr_assert_stdout_eq_str("0123456789");
}

Test(specificateur_d, return_value, .init = redirect_all_stdout)
{
    cr_assert(my_printf("J'ai %d bananes", 14000) == 18);
}

Test(specificateur_d, mix_test, .init = redirect_all_stdout)
{
    my_printf("j'ai %-20.10ld bananes", 123456789);
    cr_assert_stdout_eq_str("j'ai 0123456789           bananes");
}

Test(specificateur_d, return_value_mix_test, .init = redirect_all_stdout)
{
    cr_assert(my_printf("j'ai %-20.10ld bananes", 123456789) == 33);
}
