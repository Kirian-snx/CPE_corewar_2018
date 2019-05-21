/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** vm
*/

#include "../../include/vm.h"

unsigned char *init_vm(void)
{
    unsigned char *vm = malloc(sizeof(char) * MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++) {
        vm[i] = 0;
    }
    return (vm);
}

void print_base_space(int x)
{
    if (x > 0 && x < 225)
        printf("%X   :", x);
    else if (x > 224 && x < 4096)
        printf("%X  :", x);
    else
        printf("%X :", x);
}

void print_vm(unsigned char *vm)
{
    int x = 0;
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0) {
            if (i != 0)
                printf("\n");
            if (x == 0)
                printf("%X    :", x);
            else
                print_base_space(x);
            x += 32;
        }
        if (vm[i] < 16)
            printf(" 0%X", vm[i]);
        else
            printf(" %X", vm[i]);
    }
    printf("\n");
}