/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** check if str1 egal str2
*/

#include "../header.h"

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    if (str1 != NULL && str2 != NULL) {
        if (my_strlen(str1) != my_strlen(str2))
            return (1);
        while (str1[i] != '\0') {
            if (str1[i] != str2[i])
                return (1);
            i = i + 1;
        }
        if (str1[i] == str2[i])
            return (0);
    }
    else
        return (1);
}
