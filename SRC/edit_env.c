/*
** EPITECH PROJECT, 2019
** edit_env.c
** File description:
** set and unsetenv
*/

#include "../header.h"

char *str_env_egal(char *name, char *val)
{
    int i = 0;
    int j = 0;
    char *dest = malloc(sizeof(char)*(my_strlen(name)+my_strlen(val)+4));

    while (name[i] != '\0') {
        dest[i] = name[i];
        i = i + 1;
    }
    dest[i] = '=';
    i = i + 1;
    while (val[j] != '\0') {
        dest[i] = val[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return (dest);
}

element *new_env(element *tmp, char *n_env)
{
    element *new_node = malloc(sizeof(element));

    new_node->next = NULL;
    new_node->str = n_env;
    return (new_node);
}

element *add_env(char **tab_cmd, element *list_env)
{
    element *tmp = malloc(sizeof(element));
    element *lr = list_env;

    if (!tab_cmd[1] || !tab_cmd[2]) {
        my_putstr("setenv: Too few arguments.\n");
        return (lr);
    }
    tmp->next = list_env;
    while (list_env) {
        if (my_strcmp(name(list_env->str), tab_cmd[1]) == 0) {
            list_env->str = str_env_egal(tab_cmd[1], tab_cmd[2]);
            return (lr);
        }
        tmp = tmp->next;
        list_env = list_env->next;
    }
    tmp->next = new_env(tmp, str_env_egal(tab_cmd[1], tab_cmd[2]));
    return (lr);
}

element *rm_node(element *list_env, element *tmp)
{
    if (list_env->next) {
        tmp->next = tmp->next->next;
        return (tmp->next);
    }
    else {
        tmp->next = NULL;
        return (tmp->next);
    }
}

element *rm_env(char **tab_cmd, element *list_env)
{
    element *tmp = malloc(sizeof(element));
    element *lr = list_env;

    if (!tab_cmd[1]) {
        my_putstr("unsetenv: Too few arguments.\n");
        free(tmp);
        return (lr);
    }
    tmp->next = list_env;
    while (list_env) {
        if (my_strcmp(name(list_env->str), tab_cmd[1]) == 0) {
            list_env = rm_node(list_env, tmp);
            disp_list(list_env);
            return (lr);
        }
        tmp = tmp->next;
        list_env = list_env->next;
    }
    return (lr);
}
