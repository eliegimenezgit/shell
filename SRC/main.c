/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main of matchstick
*/

#include "../header.h"

void add_node(element *list_env, char *str)
{
    element *new_node = malloc(sizeof(element));

    while (list_env->next)
        list_env = list_env->next;
    new_node->str = str;
    new_node->next = NULL;
    list_env->next = new_node;
}

element *lister(char **env)
{
    element *list_env = malloc(sizeof(element));
    int i = 0;

    list_env->next = NULL;
    while (env[i]) {
        add_node(list_env, env[i]);
        i = i + 1;
    }
    return (list_env->next);
}

int main(int argc, char **argv, char **env)
{
    element *list_env = lister(env);

    signal(SIGINT, SIG_IGN);
    while (mysh(list_env) != -1) {
    }
    my_putstr("exit\n");
    return (0);
}
