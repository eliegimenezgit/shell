/*
** EPITECH PROJECT, 2019
** name.c
** File description:
** paher
*/

#include "../header.h"

char *name(char *path)
{
    int i = 0;
    int j = 0;
    char *name = NULL;

    if (path) {
        while (path[i] != '=')
            i = i + 1;
        name = malloc(sizeof(char) * i + 2);
        while (path[j] != '=') {
            name[j] = path[j];
            j = j + 1;
        }
        name[j] = '\0';
        return (name);
    } else
        return (path);
}
