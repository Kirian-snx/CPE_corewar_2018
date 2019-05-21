/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "../../include/vm.h"


void create_node(char *name, int len, mouv_t *mouv, unsigned char *str)
{
    champ_t *champ = malloc(sizeof(champ_t));
    champ->name = parse_name(name);
    champ->len = len;
    champ->next = mouv->list;
    champ->hex_mem = str;
    mouv->list = champ;
}

mouv_t *first_node(void)
{
    mouv_t *mouv = malloc(sizeof(mouv_t));
    champ_t *champ = malloc(sizeof(champ_t));
    champ->name = NULL;
    champ->num = 0;
    champ->status = 1;
    champ->next = NULL;
    mouv->list = champ;
    return (mouv);
}

void dispach(char **av, int ac)
{
    mouv_t *mouv = first_node();
    int len;
    unsigned char *prog_txt;
    unsigned char *vm = init_vm();
    int dump = 0;

    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-dump") == 0) {
            dump = 1;
        }else if (my_strstr(av[i], ".cor") != NULL) {
            if ((len = open_file(av[i])) != 84)
                prog_txt = get_memory(av[i]);
            create_node(av[i], len, mouv, prog_txt);
        }
    }
    if (dump == 1)
        update_vm(mouv, vm);
}

int main(int ac, char **av)
{
    if (help(av[1]) == 0)
        return (0);
    if (ac < 2)
        return (84);
    dispach(av, ac);
    return (0);
}