/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** help
*/

#include "../../include/vm.h"

int help(char *str)
{
    if (my_strcmp(str, "-h") != 0)
        return (1);
    printf("USAGE\n");
    printf("\t./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...\n");
    printf("DESCRIPTION\n");
    printf("\t-dump nbr_cycle dumps the memory after the nbr_cycle execution (if the round isn’t\n");
    printf("\t\talready over) with the following format: 32 bytes/line in\n");
    printf("\t\thexadecimal (A0BCDEFE1DD3...)\n");
    printf("\t-n prog_number sets the next program’s number. By default, the first free number\n");
    printf("\t\tin the parameter order\n");
    printf("\t-a load_address sets the next program’s loading address. When no address is\n");
    printf("\t\tspecified, optimize the addresses so that the processes are as far\n");
    printf("\t\taway from each other as possible. The addresses are MEM_SIZE modulo.\n");
    return (0);
}