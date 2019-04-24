/*
** EPITECH PROJECT, 2019
** mysh.c
** File description:
** check command
*/

#include "../header.h"

int put_error(char *cmd)
{
    my_putstr("mysh: ");
    my_putstr(cmd);
    my_putstr(" : Command not found.\n");
    return (0);
}

void change_cmd(char *cmd)
{
    int i = 0;

    while (cmd[i] != '\n') {
        i = i + 1;
    }
    cmd[i] = '\0';
}

int scan_cmd(char **tab_cmd, char *path, element *list_env)
{
    if (tab_cmd[0][0] == '\0')
        return (0);
    if (my_strcmp(tab_cmd[0], "exit") == 0)
        return (-1);
    if (my_strcmp(tab_cmd[0], "env") == 0)
        return (disp_list(list_env));
    if (my_strcmp(tab_cmd[0], "cd") == 0)
        return (dir_move(tab_cmd));
    if (exec_bin(tab_cmd, list_env) == 0)
        return (0);
    if (my_strcmp(tab_cmd[0], "setenv") == 0) {
        list_env = add_env(tab_cmd, list_env);
        return (0);
    }
    if (my_strcmp(tab_cmd[0], "unsetenv") == 0) {
        list_env = rm_env(tab_cmd, list_env);
        return (0); }
    if (cmd_path(tab_cmd, path, list_env) == 0)
        return (0);
    return (put_error(tab_cmd[0]));
}

int mysh(element *list_env)
{
    char *cmd = NULL;
    char **tab_cmd = NULL;
    size_t size = 0;
    int eval = 0;
    char *path = my_strdup("./");

    my_putstr("$>");
    if (getline(&cmd, &size, stdin) == -1)
        return (-1);
    tab_cmd = str_to_word_array(cmd, ' ');
    path = pather(list_env, path, cmd);
    eval = scan_cmd(tab_cmd, path, list_env);
    free_all(tab_cmd, path, list_env);
    return (eval);
}
