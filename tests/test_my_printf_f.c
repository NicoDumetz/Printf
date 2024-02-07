/*
** EPITECH PROJECT, 2023
** test_my_printf_f
** File description:
** unit tests for %f
*/

#include "test.h"

Test(specificateur_f, negative_value, .init = redirect_all_stdout)
{
    my_printf("%f", -123456789.0);
    cr_assert_stdout_eq_str("-123456789.000000");
}

Test(specificateur_f, negative_value_arround, .init = redirect_all_stdout)
{
    my_printf("%f", -123.4567899);
    cr_assert_stdout_eq_str("-123.456790");
}

Test(specificateur_f, negative_value_big_arround, .init = redirect_all_stdout)
{
    my_printf("%f", -123456789.9999999);
    cr_assert_stdout_eq_str("-123456790.000000");
}

Test(specificateur_f, null_value, .init = redirect_all_stdout)
{
    my_printf("%f", 0.0);
    cr_assert_stdout_eq_str("0.000000");
}

Test(specificateur_f, positive_value, .init = redirect_all_stdout)
{
    my_printf("%f", 123456789.0);
    cr_assert_stdout_eq_str("123456789.000000");
}

Test(specificateur_f, positive_value_arround, .init = redirect_all_stdout)
{
    my_printf("%f", 123.4567899);
    cr_assert_stdout_eq_str("123.456790");
}

Test(specificateur_f, positive_value_big_arround, .init = redirect_all_stdout)
{
    my_printf("%f", 123456789.9999999);
    cr_assert_stdout_eq_str("123456790.000000");
}

Test(specificateur_F, test, .init = redirect_all_stdout)
{
    my_printf("%F", 123.0);
    cr_assert_stdout_eq_str("123.000000");
}

Test(specificateur_f, space_on_positive, .init = redirect_all_stdout)
{
    my_printf("% f", 12.34);
    cr_assert_stdout_eq_str(" 12.340000");
}

Test(specificateur_f, space_on_negative, .init = redirect_all_stdout)
{
    my_printf("% f", -12.34);
    cr_assert_stdout_eq_str("-12.340000");
}

Test(specificateur_f, space_on_null, .init = redirect_all_stdout)
{
    my_printf("% f", 0.0);
    cr_assert_stdout_eq_str(" 0.000000");
}

Test(specificateur_f, plus_on_negative, .init = redirect_all_stdout)
{
    my_printf("%+f", -12.34);
    cr_assert_stdout_eq_str("-12.340000");
}

Test(specificateur_f, plus_on_negative2, .init = redirect_all_stdout)
{
    my_printf("%+f", -0.123);
    cr_assert_stdout_eq_str("-0.123000");
}

Test(specificateur_f, plus_on_null_value, .init = redirect_all_stdout)
{
    my_printf("%+f", 0.0);
    cr_assert_stdout_eq_str("+0.000000");
}

Test(specificateur_f, plus_on_pos_value, .init = redirect_all_stdout)
{
    my_printf("%+f", 0.123);
    cr_assert_stdout_eq_str("+0.123000");
}

Test(specificateur_f, plus_on_pos_value2, .init = redirect_all_stdout)
{
    my_printf("%+f", 12.34);
    cr_assert_stdout_eq_str("+12.340000");
}

Test(specificateur_f, get_gabariz, .init = redirect_all_stdout)
{
    my_printf("%*f", 10, 12.34);
    cr_assert_stdout_eq_str(" 12.34000");
}

Test(specificateur_f, gabariz, .init = redirect_all_stdout)
{
    my_printf("%10f", 0.0);
    cr_assert_stdout_eq_str("  0.000000");
}

Test(specificateur_f, gabariz_neg, .init = redirect_all_stdout)
{
    my_printf("%10f", -1.23);
    cr_assert_stdout_eq_str(" -1.230000");
}

Test(specificateur_f, gabariz_minus, .init = redirect_all_stdout)
{
    my_printf("%5f", 0.0);
    cr_assert_stdout_eq_str("0.000000");
}

Test(specificateur_f, precision_value, .init = redirect_all_stdout)
{
    my_printf("%.10f", 12.3456);
    cr_assert_stdout_eq_str("12.3456000000");
}

Test(specificateur_f, precision_neg_value, .init = redirect_all_stdout)
{
    my_printf("%.10f", -12.34);
    cr_assert_stdout_eq_str("-12.3400000000");
}

Test(specificateur_f, precision_null, .init = redirect_all_stdout)
{
    my_printf("%.0f", 12.5482);
    cr_assert_stdout_eq_str("13");
}

Test(specificateur_f, modi_h, .init = redirect_all_stdout)
{
    my_printf("%hf", 123456789.0);
    cr_assert_stdout_eq_str("123456789.000000");
}

Test(specificateur_f, modi_hh, .init = redirect_all_stdout)
{
    my_printf("%hhf", 123456789.0);
    cr_assert_stdout_eq_str("123456789.000000");
}

Test(specificateur_f, modi_l, .init = redirect_all_stdout)
{
    my_printf("%lf", 123456789.0);
    cr_assert_stdout_eq_str("123456789.000000");
}

Test(specificateur_f, modi_j, .init = redirect_all_stdout)
{
    my_printf("%jf", 123456789.0);
    cr_assert_stdout_eq_str("123456789.000000");
}

Test(specificateur_f, modi_z, .init = redirect_all_stdout)
{
    my_printf("%zf", 123456789.0);
    cr_assert_stdout_eq_str("123456789.000000");
}

Test(specificateur_f, modi_tt, .init = redirect_all_stdout)
{
    my_printf("%tf", 123456789.0);
    cr_assert_stdout_eq_str("123456789.000000");
}

Test(specificateur_f, mix_test, .init = redirect_all_stdout)
{
    my_printf("%-10.2f bananes", 123.456);
    cr_assert_stdout_eq_str("123.46    bananes");
}

Test(specificateur_f, mix_test_return_avlue, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%-10.2f bananes", 123.456) == 17);
}
