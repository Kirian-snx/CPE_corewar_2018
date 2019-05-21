/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** d4 t3
*/
#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return(0);
    for(;str[i] != '\0'; i++);
    return (i);
}
