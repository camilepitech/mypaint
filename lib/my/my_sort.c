/*
** EPITECH PROJECT, 2022
** my_type
** File description:
** library
*/
#include "../../include/libmy.h"

char *fill_str(char *str, int i, int j);

char *my_strsort(char *str)
{
    int l = my_strlen(str);

    for (int i = 0; i < l - 1; i++)
        for (int j = i + 1; j < l; j++)
            str = fill_str(str, i, j);

    return str;
}

char *fill_str(char *str, int i, int j)
{
    char tmp;

    if (str[i] > str[j]) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    return str;
}
