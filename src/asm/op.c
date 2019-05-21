/*
** EPITECH PROJECT, 2019
** op.c
** File description:
** asm
*/

#include "op.h"

op_t op_tab[] =
{
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
};

void write_in_file(int fd, char *line, size_t len)
{
    write(fd, line, len);
    //char **parse = str_to_word_array(line, ' ');
}

int assembler(char *file)
{
    FILE *fo = fopen(file, "r");
    int fc;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (fo == NULL) {
        write(2, "Empty file\n", 12);
        return (1);
    }
    fc = open(generate_name(file), O_RDWR | O_CREAT, 0777);
    while((read = getline(&line, &len, fo)) != -1) {
        write_in_file(fc, line, len);
    }
    fclose(fo);
    close(fc);
    return (0);
}

int main(int argc, char **argv)
{
    int nb_args = argc - 1;
    int ret_value = 0;

    if (nb_args == 1 && my_strcmp(argv[1], "-h") == 0) {
        manual();
        return (0);
    }
    if (nb_args != 1) {
        write(2, "Error compiling[args]. Please refer to ./asm -h\n", 49);
        return (84);
    } else if (check_name_file(argv[1]) != 0) {
        write(2, "Error compiling[file name]. Please refer to ./asm -h\n", 54);
        return (84);
    }
    ret_value = assembler(argv[1]);
    return (ret_value);
}