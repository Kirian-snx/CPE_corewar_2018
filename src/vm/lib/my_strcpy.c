/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** d6 t1
*/
#include <string.h>
#include <unistd.h>

unsigned char *my_strcpy(unsigned char *dest, unsigned char const *src)
{
    int i = 0;
    
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
