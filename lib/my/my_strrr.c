/*
** EPITECH PROJECT, 2022
** my_strrr
** File description:
** library
*/
#include "../../include/libmy.h"

int my_strocc(char *str, char *sub)
{
    int count = 0;
    int substring_length = my_strlen(sub);

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp(&str[i], sub, substring_length) == 0) {
            count++;
            i += substring_length - 1;
        }
    }

    return count;
}

int my_strncmp(const char* s1, const char* s2, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];

    return 0;
}

char *my_strsub(char* str, int index, char end)
{
    int end_index = index;
    while (str[end_index] != end) {
        end_index++;
    }

    int len = end_index - index;
    char* sub = (char*)malloc(len + 1);

    for (int i = 0; i < len; i++) {
        sub[i] = str[index + i];
    }

    sub[len] = '\0';
    return sub;
}

char *my_strdup(const char *src)
{
    size_t len = my_strlen(src) + 1;

    char *dest = malloc(sizeof(char) * len);

    my_strcpy(dest, src);

    return dest;
}
