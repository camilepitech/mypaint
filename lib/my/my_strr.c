/*
** EPITECH PROJECT, 2022
** my_strr
** File description:
** library
*/
#include "../../include/libmy.h"

char *my_strncpy(char *dest, const char *src, int n)
{
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    for (; i < n; i++)
        dest[i] = '\0';

    return dest;
}

int my_charocc(char *str, char c)
{
    int n = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            n += 1;
    return n;
}

char *my_strdel(char *str, char c)
{
    int i, j;
    int len = my_strlen(str);
    char *result = malloc(len + 1);

    for (i = j = 0; i < len; i++) {
        if (str[i] != c) {
            result[j++] = str[i];
        }
    }

    result[j] = '\0';
    return result;
}

int my_intextract(char *str, int index, char delim)
{
    int result = 0;

    for (; str[index] != delim; index++) {
        result *= 10;
        result += str[index] - '0';
    }

    return result;
}

char *my_strfuse(char *src1, char const *src2)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(src1) + my_strlen(src2) + 1));
    int i = 0, j = 0;

    for (; src1[i] != '\0'; i++)
        tmp[j + i] = src1[i];

    for (; src2[j] != '\0'; j++)
        tmp[j + i] = src2[j];

    tmp[j + i] = '\0';

    return tmp;
}
