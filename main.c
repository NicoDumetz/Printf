/*
** EPITECH PROJECT, 2023
** oinvreoe
** File description:
** breple
*/

#include "include/mini_printf.h"

int main(void){
    int nb = printf("coucou %                                              c j'ai %d\n", 'a', 18);
    printf("%d \n", nb);

    int	nb2 = mini_printf("coucou %                                         c j'ai %d\n", 'a', 18);
    mini_printf("%d \n", nb2);
}
