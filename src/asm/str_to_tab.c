/*
** EPITECH PROJECT, 2019
** str_to_tab.c
** File description:
** parse str into char**
*/

#include "op.h"

int nb_words(char *str, char sep)
{
    int count = 0;
    int bol = 0;

    for (int i = 0; str[i] != '\0';) {
        while (str[i] == sep || str[i] == '\t') {
            i++;
            bol = 0;
        }
        while (str[i] != sep && str[i] != '\t' && str[i] != '\0') {
            i++;
            bol = 1;
        }
        if (bol == 1)
            count++;
    }
    return (count);
}

int count_let(char *str, char sep)
{
    int let = 0;
    static int idx = 0;

    if (str == NULL)
        return (0);
    while ((str[idx] == sep || str[idx] == '\t') && str[idx] != 0)
        idx++;
    for (; str[idx] != 0 && str[idx] != sep && str[idx] != '\t'; idx++)
        let++;
    while ((str[idx] == sep || str[idx] == '\t') && str[idx] != 0)
        idx++;
    while ((str[idx] == sep || str[idx] == '\t') && str[idx] != 0)
        idx++;
    if (str[idx] == '\0')
        idx = 0;
    return (let);
}

char **malloc_tab(char *str, int nbw, char sep)
{
    char **dest;

    dest = malloc(sizeof(*dest) * (nbw + 1));
    for (int i = 0; i < nbw; i++)
        dest[i] = malloc(sizeof(char) * count_let(str, sep) + 1);
    return (dest);
}

char **str_to_word_array(char *str, char sep)
{
    int nbw = nb_words(str, sep);
    char **dest = malloc_tab(str, nbw, sep);
    int y = 0;
    int x = 0;

    dest[nbw] = NULL;
    for (int i = 0; str[i] != '\0';) {
        for (; str[i] == sep || str[i] == '\t'; i++);
        while (str[i] != sep && str[i] != '\0' && str[i] != '\t') {
            dest[y][x] = str[i];
            dest[y][x + 1] = '\0';
            x++;
            i++;
            if (str[i] == sep) {
                y++;
                x = 0;
            }
        }
    }
    return (dest);
}