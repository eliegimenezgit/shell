/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** return malloc str
*/

#include "../header.h"

char *my_strdup(char const *str)
{
    int i = 0;
    char *dest = malloc(sizeof(char)*my_strlen(str) + 1);

    while (str[i] != '\0') {
        dest[i] = str[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
