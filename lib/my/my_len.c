/*
** EPITECH PROJECT, 2022
** my_len
** File description:
** library
*/
#include "../../include/libmy.h"

int my_nbrlen(int nb)
{
    int i = 1;
    int n = 1;

    while ((nb / i) >= 10) {
        i *= 10;
        n++;
    }

    return (n);
}

int my_tablen(char **tab)
{
    int s = 0;
    for (int i = 0; tab[i] != NULL; i++)
        s++;

    return s;
}

int my_longestlen(char **tab)
{
    int longest = 0;

    for (int i = 0; tab[i] != NULL; i++)
        if (my_strlen(tab[i]) > longest)
            longest = my_strlen(tab[i]);

    return longest;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}

int my_strnlen(char const *str, int index, char delim)
{
    int i = index;

    while (str[i] != delim && str[i] != '\0')
        i++;

    return (i);
}
