/*
** EPITECH PROJECT, 2019
** move_dir.c
** File description:
** cd
*/

#include "../header.h"

int dir_move(char **tab_cmd)
{
    int i = 1;

    while (tab_cmd[i]) {
        if (tab_cmd[i][0] != '-') {
            if (chdir(tab_cmd[i]) == -1) {
                my_putstr("mysh: cd: ");
                my_putstr(tab_cmd[i]);
                my_putstr(": No such file or directory\n");
            }
            return (0);
        }
        i = i + 1;
    }
    return (0);
}
