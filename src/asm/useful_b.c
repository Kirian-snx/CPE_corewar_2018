/*
** EPITECH PROJECT, 2019
** useful_b.c
** File description:
** useful functions
*/

#include "op.h"

char *generate_name(char *file)
{
    char **parse = str_to_word_array(file, '.');
    int len = len_tab(parse);
    char *temp = NULL;
    char *str_final = NULL;

    if (len != 2) {
        free_tab(parse);
        return (NULL);
    }
    temp = parse[0];
    str_final = my_strcat(temp, ".cor");
    free_tab(parse);
    free(temp);
    return (str_final);
}

char *my_strcat(char *s1, char *s2)
{
    int tot_dest = my_strlen(s1) + my_strlen(s2);
    char *dest = malloc(sizeof(char) * (tot_dest + 1));
    int i = 0;

    for (i = 0; s1[i] != '\0'; i++)
        dest[i] = s1[i];
    for (int j = 0; s2[j] != '\0'; j++, i++)
        dest[i] = s2[j];
    dest[i] = '\0';
    return (dest);
}

int len_tab(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i] != NULL; ++i) {
        ++count;
    }
    return (count);
}