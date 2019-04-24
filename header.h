/*
** EPITECH PROJECT, 2018
** header.h
** File description:
** header file
*/

#ifndef MY_HEADER_
#define MY_HEADER_

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct element_t
{
    char *str;
    struct element_t *next;
} element;

int disp_list(element *list);
char **str_to_word_array(char *str, char c);
int my_getnbr(char const *str);
void my_putchar(char const c);
void my_put_nbr(int nbr);
void my_putstr(char *str);
int my_strlen(char const *str);
char *my_strdup(char const *str);
int my_strcmp(char *str1, char *str2);

int main(int argc, char **argv, char **env);
int mysh(element *list_env);
void free_all(char **cmd, char *path, element *list);
int cmd_path(char **tab_cmd, char *path, element *list_env);
int exec_cmd(char *full_path, char **tab_cmd, char **envp);
int exec_bin(char **tab_cmd, element *list_env);
element * add_env(char **tab_cmd, element *list_env);
element *rm_env(char **tab_cmd, element *list_env);
char **list_to_tab(element *list_env);
char *pather(element *list_env, char *path, char *cmd);
char *cmd_in_path(char *str, char *cmd);
int dir_move(char **tab_cmd);
char *name(char *path);

#endif /*MY_HEADER_*/
