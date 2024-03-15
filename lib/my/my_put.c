/*
** EPITECH PROJECT, 2022
** my_put
** File description:
** library
*/
#include "../../include/libmy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void my_put_tab(char **buff, char *separator)
{
    int len = my_strlen(separator);
    for (int i = 0; buff[i] != NULL; i++) {
        write(1, buff[i], my_strlen(buff[i]));
        write(1, separator, len);
    }
}

void my_put_nbr(int nb)
{
    int modulo;

    modulo = 0;
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + '0');
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (- 1);
        if (nb <= 9 && nb >= 0)
        my_put_nbr(nb);
    }
    if (nb > 9) {
        modulo = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(modulo + '0');
    }
}
