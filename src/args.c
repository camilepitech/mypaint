/*
** EPITECH PROJECT, 2022
** args.c
** File description:
** args
*/
#include "../include/libmy.h"

int args_check(int ac, char **av)
{
    if (ac != 1) {
        write(2, "No arguments are expected\n", 26);
        return 0;
    }

    return 1;
}
