/*
** EPITECH PROJECT, 2023
** test_my_printf_s
** File description:
** tests for s specificator
*/

#include "test.h"

Test(specificateur_s, empty_string, .init = redirect_all_stdout)
{
    my_printf("Ce que je préfère plus que les bananes c'est: %s", "");
    cr_assert_stdout_eq_str("Ce que je préfère plus que les bananes c'est: ");
}

Test(specificateur_s, normal_string, .init = redirect_all_stdout)
{
    my_printf("Ce que je préfère plus que les bananes c'est: %s", "rien parce que les bananes sont un don des dieux");
    cr_assert_stdout_eq_str("Ce que je préfère plus que les bananes c'est: rien parce que les bananes sont un don des dieux");
}

Test(specificateur_s, return_value, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%s", "bananes") == 7);
}

Test(specificateur_s, gabariz, .init = redirect_all_stdout)
{
    my_printf("%10s", "bananes");
    cr_assert_stdout_eq_str("   bananes");
}

Test(specificateur_s, gabariz_minus, .init = redirect_all_stdout)
{
    my_printf("%-10s", "bananes");
    cr_assert_stdout_eq_str("bananes   ");
}

Test(specificateur_s, precision, .init = redirect_all_stdout)
{
    my_printf("%.5s", "bananes");
    cr_assert_stdout_eq_str("banan");
}

Test(specificateur_s, non_crash_h, .init = redirect_all_stdout)
{
    my_printf("%hs", "bananes");
    cr_assert_stdout_eq_str("bananes");
}

Test(specificateur_s, non_crash_hh, .init = redirect_all_stdout)
{
    my_printf("%hhs", "bananes");
    cr_assert_stdout_eq_str("bananes");
}

Test(specificateur_s, crash_l, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%ls", "bananes") == -1);
}

Test(specificateur_s, crash_ll, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%lls", "bananes") == -1);
}

Test(specificateur_s, crash_q, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%qs", "bananes") == -1);
}

Test(specificateur_s, crash_j, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%js", "bananes") == -1);
}

Test(specificateur_s, crash_z, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%zs", "bananes") == -1);
}

Test(specificateur_s, crash_tt, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%ts", "bananes") == -1);
}

Test(specificateur_s, crash_L, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%Ls", "bananes") == -1);
}

Test(specificateur_S, crash_S, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%S", "bananes") == -1);
}

Test(specificateur_c, only_test_existing, .init = redirect_all_stdout)
{
    my_printf("%cananes", 'b');
    cr_assert_stdout_eq_str("bananes");
}

Test(specificateur_s, mix_test, .init = redirect_all_stdout)
{
    my_printf("Oh oui les %-10.5hhs!!!", "bananes");
    cr_assert_stdout_eq_str("Oh oui les banan     !!!");
}

Test(speficateur_s, return_value_mix_test, .init = redirect_all_stdout)
{
    cr_assert(my_printf("Oh oui les %-10.5hhs!!!", "bananes") == 24);
}
