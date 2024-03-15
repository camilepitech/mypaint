/*
** EPITECH PROJECT, 2021
** my_parser
** File description:
** library
*/
#include "../../include/libmy.h"

int my_str2int(char *str)
{
    int result = 0;
    int sign = 1;

    if (str[0] == '-') {
        sign = -1;
        str++;
    }

    while (*str != '\0') {
        if (*str < '0' || *str > '9')
            break;

        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

char *my_int2str(int nb)
{
    int i;
    int len = my_nbrlen(nb);

    char *nbr = malloc(sizeof(char) * nb);

    for (i = 0; i < len; i++) {
        nbr[i] = nb % 10 + '0';
        nb /= 10;
    }
    nbr[i] = '\0';

    return my_revstr(nbr);
}

int my_int2bin(unsigned long nb)
{
    if (nb > 1)
        my_int2bin(nb / 2);
    my_put_nbr(nb % 2);
    return (0);
}

char **my_str2tab(char *str, int index, char delim, int end)
{
    int nb_words = my_charocc(str, delim) + end;
    int k = 0, j = 0;

    char **buffer = malloc(sizeof(char *) * (nb_words + 1));
    for (int i = index; k < nb_words; i++) {
        delim = (end == 1 && (k + 1) == nb_words) ? '\0' : delim;
        int nb_char = my_strnlen(str, i, delim);

        buffer[k] = malloc(sizeof(char) * nb_char + 1);
        for (j = 0; str[i] != delim; j++) {
            buffer[k][j] = str[i];
            i++;
        }
        buffer[k][j] = '\0';
        k++;
    }
    buffer[k] = NULL;

    return buffer;
}

char *my_tab2str(char **strings, char separator)
{
    int tablen = my_tablen(strings), total_len = 0, offset = 0;

    for (int i = 0; i < tablen; i++)
        total_len += my_strlen(strings[i]);
    total_len += tablen - 1;

    char* result = malloc(total_len + 1);
    for (int i = 0; i < tablen; i++) {
        int length = my_strlen(strings[i]);
        for (int j = 0; j < length; j++)
            result[offset + j] = strings[i][j];
        offset += length;
        if (i < tablen - 1) {
            result[offset] = separator;
            offset++;
        }
    }
    result[total_len] = '\0';

    return result;
}
