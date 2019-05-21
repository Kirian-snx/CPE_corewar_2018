/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** dump
*/

#include "../../include/vm.h"


unsigned char*loop_vm(mouv_t *mouv, unsigned char *vm)
{
    int i = 0;
    champ_t *tmp = mouv->list;

    for(; tmp != NULL; tmp = tmp->next) {
        if (tmp->hex_mem != NULL) {
            printf("{%s}\n", tmp->name);
            for(int j = tmp->len / 2; j < tmp->len; i++, j++) {
                vm[i] = tmp->hex_mem[j];
            }
            i += 64;
        }
        printf("next tmp\n");
    }
    return (vm);
}

void update_vm(mouv_t *mouv, unsigned char *vm)
{
    vm = loop_vm(mouv, vm);
    print_vm(vm);
}