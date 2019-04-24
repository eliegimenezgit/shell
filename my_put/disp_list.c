/*
** EPITECH PROJECT, 2018
** disp_list.c
** File description:
** disp.c list with put
*/

#include "../header.h"

int disp_list(element *list)
{
    if (list) {
        while (list->next) {
            my_putstr(list->str);
            list = list->next;
            my_putchar('\n');
        }
        my_putstr(list->str);
        my_putchar('\n');
    }
    return (0);
}
