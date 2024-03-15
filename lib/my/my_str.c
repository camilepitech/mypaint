/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** library
*/
#include "../../include/libmy.h"

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str);
    char temp[len + 1];
    while (i < len / 2) {
        temp[i] = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp[i];
        i++;
    }
    return str;
}

char *my_strcat(char *dest, char const *src)
{
    int j = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[j + i] = src[i];
        i++;
    }

    dest[j + i] = '\0';
    return (dest);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int my_strcmp(char const *s1, char const *s2)
{
    int len = my_strlen(s1);
    if (my_strlen(s2) > my_strlen(s1))
        len = my_strlen(s2);

    for (int i = 0; i < len; i++)
        if (s1[i] != s2[i])
            return 0;

    return 1;
}

int my_strcontains(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
    return 0;
}
