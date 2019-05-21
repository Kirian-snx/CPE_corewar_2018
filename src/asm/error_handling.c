/*
** EPITECH PROJECT, 2019
** error_handling.c
** File description:
** error handling functions
*/

#include "op.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; ++i)
        free(tab[i]);
}

int check_name_file(char *path)
{
    char **parse = str_to_word_array(path, '.');
    int len = len_tab(parse);

    if (len != 2) {
        free_tab(parse);
        return (1);
    }
    if (my_strcmp(parse[1], "s") != 0) {
        free_tab(parse);
        return (1);
    }
    free_tab(parse);
    return (0);
}