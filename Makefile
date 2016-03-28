##
## Makefile for Makefile in /home/zeng_d/test/10/test
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Mon Oct 12 13:31:18 2015 David Zeng
## Last update Mon Mar 28 16:24:26 2016 David Zeng
##

SRC	= main.c \
	  src/init_minishell2.c \
	  src/convert_env.c \
	  src/my_parsing.c \
	  src/my_str_to_tab.c \
	  src/my_builtins.c \

NAME	= mysh

LIB	= libmy.a

LIST	= libmlist.a

CC	= gcc

OBJ	= $(SRC:.c=.o)

CFLAGS	= -g -W -Werror -Wall -Wno-unused-variable -Wno-unused-parameter

INC	= -L./lib -lmlist -lmy -I./include/

PATH1	= ./lib/my/

PATH2	= ./lib/mlist/

all: 	  ./lib/$(LIB) ./lib/$(LIST) $(NAME)

$(NAME):  $(OBJ)
	  @$(CC) -o $(NAME) $(OBJ) $(INC) $(CFLAGS)

./lib/$(LIB):
	  @$(MAKE) -C $(PATH1) yo

./lib/$(LIST):
	  @$(MAKE) -C $(PATH2) yo

clean:
	  @rm -f $(OBJ)

fclean:	  clean
	  @rm -f $(NAME)

re:	  fclean all

.PHONY:	  all clean fclean re

yo:	  all clean

.c.o:
	  @$(CC) -c $< -o $@ $(INC) $(CFLAGS)
