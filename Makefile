##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## file of compilation
##

SRC = ./SRC/main.c                 \
      ./SRC/mysh.c                 \
      ./SRC/cmd_path.c             \
      ./SRC/exec_bin.c             \
      ./SRC/edit_env.c             \
      ./SRC/dir_move.c             \
      ./SRC/pather.c               \
      ./SRC/free_all.c             \
      ./SRC/name.c                 \
      ./my_put/str_to_word_array.c \
      ./my_put/my_strcmp.c         \
      ./my_put/disp_list.c         \
      ./my_put/my_strdup.c         \
      ./my_put/my_putchar.c        \
      ./my_put/my_put_nbr.c        \
      ./my_put/my_putstr.c         \
      ./my_put/my_strlen.c         \
      ./my_put/my_getnbr.c


OBJ = $(SRC:.c=.o)

NAME = mysh

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -I.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
