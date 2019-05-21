/*
** EPITECH PROJECT, 2018
** my_isnum
** File description:
** true num string
*/

#include <unistd.h>

int my_str_isnum(char const *str)
{
    int check = 1;

    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            check = 1;
        }
        else {
            return (0);
        }
    }
    return (check);
}