/*
** EPITECH PROJECT, 2019
** op.h
** File description:
** h file
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef _OP_H_
# define _OP_H_

# define MEM_SIZE                (6*1024)
# define IDX_MOD                 512   /* modulo of the index < */
# define MAX_ARGS_NUMBER         4     /* this may not be changed 2^*IND_SIZE */

# define COMMENT_CHAR            '#'
# define LABEL_CHAR              ':'
# define DIRECT_CHAR             '%'
# define SEPARATOR_CHAR          ','

# define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING         ".name"
# define COMMENT_CMD_STRING      ".comment"

# define REG_NUMBER      16              /* r1 <--> rx */

typedef char    args_type_t;

# define T_REG           1       /* register */
# define T_DIR           2       /* direct  (ld  #1,r1  put 1 into r1) */
# define T_IND           4       /* indirect always relative ( ld 1,r1 put what's in the address (1+pc) into r1 (4 bytes )) */
# define T_LAB           8       /* LABEL */

typedef struct  op_s
{
   char         *mnemonique;
   char         nbr_args;
   args_type_t  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
} op_t;

# define IND_SIZE        2
# define DIR_SIZE        4
# define REG_SIZE        DIR_SIZE

extern  op_t    op_tab[];

# define PROG_NAME_LENGTH        128
# define COMMENT_LENGTH          2048

typedef struct header_s
{
   int  magic;
# define COREWAR_EXEC_MAGIC      0xea83f3
   char prog_name[PROG_NAME_LENGTH + 1];
   int  prog_size;
   char comment[COMMENT_LENGTH + 1];
} header_t;

# define CYCLE_TO_DIE    1536    /* number of cycle before beig declared dead */
# define CYCLE_DELTA     5
# define NBR_LIVE        40

/*FUNCTIONS*/

//op.c
void manual(void);
int assembler(char *);

//useful_a.c
int my_putstr(char const *);
int my_strcmp(char const *, char const *);
void my_putchar(char);
int my_strlen(char const *);

//error_handling.c
int check_name_file(char *);
void free_tab(char **);

//str_to_tab.c
int nb_words(char *, char);
int count_let(char *, char);
char **malloc_tab(char *, int, char);
char **str_to_word_array(char *, char);

//useful_b.c
char *my_strcat(char *, char *);
int len_tab(char **tab);
char *generate_name(char *);

#endif