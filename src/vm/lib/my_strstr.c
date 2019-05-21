/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** d6 t4
*/

#include <string.h>
#include <unistd.h>

char *condif(int i, int *no_find, char *str, char const *to_find)
{
    for (int j = 0; to_find[j] != '\0' && str[i] != '\0'; j++) {
        if (str[i + j] != to_find[j]) {
            *no_find = 0;
        }
    }
    return (NULL);
}

char *my_strstr(char *str, char const *to_find)
{
    int no_find = 1;
    
    for (int i = 0; str[i] != '\0' && str != NULL; i++) {
        no_find = 1;
        condif(i, &no_find, str, to_find);
        if (no_find != 0)
            return (str + i);
    }
    return (NULL);
}
