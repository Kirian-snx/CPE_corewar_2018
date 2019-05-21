/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** d4 t5
*/

#include <string.h>
#include <unistd.h>

int count_neg(int nega, int nbr)
{
    if ((nega % 2) == 1)
        nbr = nbr * (-1);
    return (nbr);
}

int my_getnbr(char const *str)
{
    int nbr = 0;
    int nega = 0;
    int i;
    for (i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            nega++;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++)
        nbr = nbr * 10 + (str[i] -48);
    return (count_neg(nega, nbr));
}
