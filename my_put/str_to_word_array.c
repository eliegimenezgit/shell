/*
** EPITECH PROJECT, 2019
** str_to_word_array.c
** File description:
** create tab string
*/

#include "../header.h"

char *select_word(char *wrd, char *str, int end, int start)
{
    int i = 0;

    while (start != end) {
        wrd[i] = str[start];
        i = i + 1;
        start = start + 1;
    }
    wrd[i] = '\0';
    return (wrd);
}

char *push_the_word(char *str, int word, char c)
{
    char *wrd;
    int i = 0;
    int j = 0;

    while (j != word) {
        if (str[i] == c || str[i] == '\t') {
            while (str[i] == c || str[i] == '\t') {
                i = i + 1;
            }
            if (str[i] != '\n')
                j = j + 1;
        } else
            i = i + 1;
    }
    j = i;
    while (str[i] != c && str[i] != '\t' && str[i] != '\n') {
    i = i + 1;
    }
    wrd = malloc(sizeof(char)*(i + 1));
    return (select_word(wrd, str, i, j));
}

void worder(char **str_tab, char *str, int word, char c)
{
    int i = 0;

    while (i != word) {
        str_tab[i] = push_the_word(str, i, c);
        i = i + 1;
    }
    str_tab[i] = NULL;
}

char **str_to_word_array(char *str, char c)
{
    char **str_tab = NULL;
    int i = 0;
    int word = 1;

    while (str[i] != '\0') {
        if (str[i] == c || str[i] == '\t') {
            while (str[i] == c || str[i] == '\t') {
                i = i + 1;
            }
            if (str[i] != '\n')
                word = word + 1;
        } else
            i = i + 1;
    }
    str_tab = malloc(sizeof(char *)*(word + 1));
    worder(str_tab, str, word, c);
    return (str_tab);
}
