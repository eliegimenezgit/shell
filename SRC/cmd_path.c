/*
** EPITECH PROJECT, 2019
** exec_cmd.c
** File description:
** exec and return ev
*/

#include "../header.h"

char *cmd_in_path(char *path, char *cmd)
{
    int size = (my_strlen(path) + my_strlen(cmd));
    int i = 0;
    int j = 0;
    char *full_path = malloc(sizeof(char) * size + 2);

    while (path[i] != '\0') {
        full_path[i] = path[i];
        i = i + 1;
    }
    full_path[i] = '/';
    i = i + 1;
    while (cmd[j] != '\n' && cmd[j] != '\0') {
        full_path[i] = cmd[j];
        i = i + 1;
        j = j + 1;
    }
    full_path[i] = '\0';
    return (full_path);
}

char **list_to_tab(element *list_env)
{
    element *tmp = list_env;
    char **tab_env = NULL;
    int i = 0;
    int j = 0;

    while (tmp) {
        tmp = tmp->next;
        i = i + 1;
    }
    tab_env = malloc(sizeof(char *) * (i + 2));
    while (list_env) {
        tab_env[j] = my_strdup(list_env->str);
        j = j + 1;
        list_env = list_env->next;
    }
    tab_env[j] = NULL;
    return (tab_env);
}

int exec_cmd(char *full_path, char **tab_cmd, char **envp)
{
    pid_t pid = fork();

    if (pid == -1) {
        return (-1);
    } else if (pid == 0) {
        if (execve(full_path, tab_cmd, envp) == -1)
            return (-1);
    } else
        wait(NULL);
    return (0);
}

int cmd_path(char **tab_cmd, char *path, element *list_env)
{
    char *full_path = cmd_in_path(path, tab_cmd[0]);

    if (path == NULL)
        return (84);
    if (access(full_path, X_OK) == -1)
        return (84);
    else if (exec_cmd(full_path, tab_cmd, list_to_tab(list_env)) == -1)
        return (84);
    return (0);
}
