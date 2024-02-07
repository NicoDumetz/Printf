/*
** EPITECH PROJECT, 2023
** test_my_printf_percent
** File description:
** tests for printf % flag
*/

#include "test.h"

Test(specificateur_percent, test, .init = redirect_all_stdout)
{
    my_printf("Notre ADN est à 50%% le même que celui d'une banane");
    cr_assert_stdout_eq_str("Notre ADN est à 50% le même que celui d'une banane");
}

Test(specificateur_percent, return_value, .init = redirect_all_stdout)
{
    cr_assert(my_printf("bananes%%") == 8); 
}

Test(specificateur_percent, crash_test, .init = redirect_all_stdout)
{
    cr_assert(my_printf("%%Bananes%") == -1);    
}
