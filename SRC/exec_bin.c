/*
** EPITECH PROJECT, 2019
** exec_bin.c
** File description:
** exec ./cmd
*/

#include "../header.h"

int exec_bin(char **tab_cmd, element *list_env)
{
    if (tab_cmd[0][0] == '.' && tab_cmd[0][1] == '/') {
        if (access(tab_cmd[0], X_OK) == - 1)
            return (-1);
        else if (exec_cmd(tab_cmd[0], tab_cmd, list_to_tab(list_env)) == -1)
            return (-1);
    } else
        return (-1);
    return (0);
}
