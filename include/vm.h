/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** header for vm
*/

#ifndef VM_H_
#define VM_H_


#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include "op.h"

typedef struct champ
{
    char *name;
    int num;
    int status;
    int len;
    unsigned char *hex_mem;
    struct champ *next;
}champ_t;

typedef struct mouv
{
    struct champ *list;
}mouv_t;

/* lib */
int my_strcmp(char const *s1, char const *s2);
unsigned char *my_strcpy(unsigned char *dest, unsigned char const *src);
int my_strlen(char const *str);
char *my_strstr(char *str, char const *to_find);
int my_str_isnum(char const *str);
int my_getnbr(char const *str);
/* end */

/* handing */
int help(char *str);

/* end */

/* VM */
unsigned char *init_vm(void);
void print_vm(unsigned char *vm);
/* END */

/* Dump memory */
void dump(int after);
void update_vm(mouv_t *mouv, unsigned char *vm);
unsigned char*loop_vm(mouv_t *mouv, unsigned char *vm);
/* END */

/* Parsing */
char *parse_name(char *str);
unsigned char *get_memory(char const *filpath);
int open_file(char const *filpath);
/* END */


#endif /* !VM_H_ */
