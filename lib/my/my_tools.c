/*
** EPITECH PROJECT, 2022
** my_tools
** File description:
** library
*/
#include "../../include/libmy.h"

char *my_filestr(char *file)
{
    struct stat info = {0};
    stat(file, &info);
    int size = info.st_size;

    int fd = open(file, O_RDONLY);
    char *buff = malloc(sizeof(char) * size + 1);
    int rd = read(fd, buff, size);

    close(fd);
    buff[size] = '\0';

    return buff;
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void pass(void)
{

}

void space(void)
{
    my_putchar(' ');
}

void back(void)
{
    my_putchar('\n');
}

// ----------------------------> ALTERNATIVE WHEN OPEN/READ ARE FORBIDDEN
// char *my_filestr(char *file)
// {
//     char *contents = NULL;
//     size_t len = 0;
//     ssize_t read;
//     char *str = "";

//     FILE *fp = fopen(file, "r");
//     if (fp == NULL)
//         return NULL;

//     while ((read = getline(&contents, &len, fp)) != -1)
//         str = my_strfuse(str, contents);

//     fclose(fp);
//     return str;
// }
