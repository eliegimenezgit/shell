/*
** EPITECH PROJECT, 2019
** pather.c
** File description:
** access path
*/

#include "../header.h"

int access_with_cmd(char *path, char *cmd)
{
    char *real_path = cmd_in_path(path, cmd);

    if (access(real_path, X_OK) != -1) {
        return (0);
    }
    return (1);
}

char *cutted(char *first_path)
{
    int i = 0;
    int j = 0;
    char *dest = NULL;

    while (first_path[i + j] != '\0') {
        while (first_path[j] != '=')
            j = j + 1;
        i = i + 1;
    }
    dest = malloc(sizeof(char) * i + 2);
    j = j + 1;
    i = 0;
    while (first_path[j] != '\0') {
        dest[i] = first_path[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return (dest);
}

char *str_to_path_access(char *str, char *cmd)
{
    int i = 1;
    char **tab_path = str_to_word_array(str, ':');

    if (access_with_cmd(cutted(tab_path[0]), cmd) == 0)
        return (tab_path[0]);
    while (tab_path[i]) {
        if (access_with_cmd(tab_path[i], cmd) == 0)
            return (tab_path[i]);
        i = i + 1;
    }
    return (my_strdup("/usr/bin/"));
}

char *pather(element *list_env, char *path, char *cmd)
{
    while (list_env) {
        if (list_env->str && my_strlen(list_env->str) > 4) {
            if (list_env->str[0] == 'P' && list_env->str[1] == 'A') {
                if (list_env->str[2] == 'T' && list_env->str[3] == 'H')
                    path = str_to_path_access(list_env->str, cmd);
            }
        }
        list_env = list_env->next;
    }
    return (path);
}
