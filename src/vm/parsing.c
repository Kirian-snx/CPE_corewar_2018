/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** parsing
*/

#include "../../include/vm.h"

char *parse_name(char *str)
{
    int len = my_strlen(str);
    char *name = malloc(sizeof(char) * (len));
    int i = 0;
    int j = 0;
    int tmp = 0;

    if(str == NULL)
        return (NULL);
    for (int u = 0; str[u] != '\0'; u++) {
        if (str[u] == '/') {
            i = u;
            if (i > tmp)
                tmp = i;
        }
    }
    i = 0;
    for (j = tmp + 1; j < len - 4; j++, i++)
        name[i] = str[j];
    name[i] = '\0';
    return (name);
}

int open_file(char const *filpath)
{
    int fd = open(filpath, O_RDONLY);
    char *buff;
    struct stat buffer;
    int len;

    stat(filpath, &buffer);
    buff = malloc(sizeof(char) * (buffer.st_size + 1));
    if (fd == -1) {
        write(2, "No such file or directory\n", 27);
        return (84);
    }
    len = read(fd , buff, buffer.st_size);
    buff[buffer.st_size] = '\0';
    close (fd);
    free(buff);
    return (len);
}

unsigned char *get_memory(char const *filpath)
{
    int fd = open(filpath, O_RDONLY);
    unsigned char *buf;
    struct stat st;
    stat(filpath, &st);
    buf = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, buf, st.st_size);
    buf[st.st_size] = '\0';
    close(fd);
    return (buf);
}