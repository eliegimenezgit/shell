/*
** EPITECH PROJECT, 2019
** free_all
** File description:
** free cmd path env
*/

#include "../header.h"

void free_all(char **cmd, char *path, element *list)
{
    int i = 0;

    while (cmd[i]) {
        free(cmd[i]);
        i = i + 1;
    }
    free(cmd[i]);
}
