/*
** EPITECH PROJECT, 2022
** my_type
** File description:
** library
*/
#include "../../include/libmy.h"

int my_isintstr(char *str)
{
    int i = 0;
    if (str[0] == '-')
        i = 1;

    for (i; str[i] != '\0'; i++)
        if (!(str[i] >= '0' || str[i] <= '9'))
            return 0;

    return 1;
}

int my_isint(char c)
{
    return (c >= '0' && c <= '9');
}

int my_isalpha(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int my_isalphastr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!(str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z'))
            return 0;

    return 1;
}

int my_isalphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_isalpha(str[i]) && !my_isint(str[i]))
            return 0;

    return 1;
}
