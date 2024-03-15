/*
** EPITECH PROJECT, 2022
** my_float
** File description:
** library
*/
#include "../../include/libmy.h"

void print_float(long integer, long decimal, long n, int z);

char *remove_zeros(long decimal);

void my_put_float(double nb, int p, int z)
{
    int negative = 0;
    if (nb < 0) {
        nb *= -1;
        negative = 1;
    }
    long long limit = 1;
    long n = p;
    long integer = nb;
    for (p; p > 0; p--)
        limit *= 10;
    long decimal = (nb * limit - integer * limit) + limit;
    long round = (long)(nb * (limit * 10) - integer * (limit * 10)) % 10;
    int last = (decimal + 1 == limit) ? 1 : 0;
    decimal = (round > 4) ? decimal + 1 : decimal;
    decimal = (last == 1 && decimal == limit) ? 0 : decimal;
    integer = (decimal == 0 && last == 1) ? integer + 1 : integer;

    if (negative == 1)
        my_putchar('-');
    print_float(integer, decimal, n, z);
}

char *remove_zeros(long decimal)
{
    decimal = (int)decimal;
    char *tmp = my_int2str(decimal);
    char *str = malloc(sizeof(char) * my_nbrlen(decimal) - 1);
    for (int i = 1; i < my_strlen(tmp); i++)
        str[i - 1] = tmp[i];
    return (str);
}

void print_float(long integer, long decimal, long n, int z)
{
    my_put_nbr(integer);

    if (n > 0)
        my_putchar('.');

    if (z == 0)
        while (decimal % 10 == 0)
            decimal /= 10;

    char *decimalstr = remove_zeros(decimal);
    my_putstr(decimalstr);

    if (decimal == 0 && z == 1)
        for (int i = 1; i < n; i++)
            my_put_nbr(0);
}

void my_put_scientific(double decimal, char c, int p, int z)
{
    int i = 0;

    for (i; !(decimal < 10 && decimal > -10); i++)
        decimal /= 10;
    if (p == 0)
        decimal += 1;

    my_put_float(decimal, p, z);

    my_putchar(c);
    my_putchar('+');

    if (my_nbrlen(i) < 2)
        my_putchar('0');

    my_put_nbr(i);
}
