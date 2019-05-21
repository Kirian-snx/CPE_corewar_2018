/*
** EPITECH PROJECT, 2019
** useful_a.c
** File description:
** useful functions
*/

#include "op.h"

void manual(void)
{
    my_putstr("USAGE\n");
    my_putstr("        ./asm file_name[.s]\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("        file_name       file in assembly language to be ");
    my_putstr("converted into file_name.cor, an\n");
    my_putstr("                        executable in the Virtual Machine.\n");
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    while (s1[i] && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}