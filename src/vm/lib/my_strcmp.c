/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** d6 t5
*/
#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    for (;s1[i] != '\0' && s2[j] != '\0'; i++, j++)
        if (s1[i] != s2[j])
            break;
    return (s1[i] - s2[j]);
}

