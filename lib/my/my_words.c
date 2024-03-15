/*
** EPITECH PROJECT, 2021
** my_parser
** File description:
** library
*/
#include "../../include/libmy.h"

int my_wordscount(char *str)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            in_word = 0;
        }

        if (!(str[i] == ' ' || str[i] == '\t') && !in_word) {
            in_word = 1;
            count++;
        }
    }

    return count;
}

int my_onlycontains(char *str, char *chars)
{
    int len = my_strlen(str);
    int occurences = 0;

    for (int i = 0; chars[i] != '\0'; i++)
        occurences += my_charocc(str, chars[i]);

    return (len == occurences) ? 1 : 0;
}

char **my_getwords(char *str)
{
    int num_words = my_wordscount(str);

    char **words = malloc(sizeof(char *) * (num_words + 1));
    words[0] = NULL;

    char *word = strtok(str, " \t\n");

    for (int i = 0; word != NULL; i++) {
        words[i] = word;
        word = strtok(NULL, " \t\n");
    }

    words[num_words] = NULL;

    return words;
}

int my_skipline(char *str, int index, char c)
{
    int i = index;
    while (str[i] != c)
        i++;

    return i + 1;
}

int my_isintab(char **tab, char *str)
{
    for (int i = 0; i < my_tablen(tab); i++)
        if (my_strcmp(tab[i], str))
            return 1;

    return 0;
}
