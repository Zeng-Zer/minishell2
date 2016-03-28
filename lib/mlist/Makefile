##
## Makefile for mklib in /home/zeng_d/usefull/my_lib/source
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Sun Oct 11 14:33:50 2015 David Zeng
## Last update Mon Mar 28 01:18:51 2016 David Zeng
##

SRC=	  my_add_first.c \
	  my_add_list.c \
	  my_declare_list.c \
	  my_del_node.c \
	  my_free_all.c \
	  my_free_list.c \
	  my_show_list.c \

OBJ=	  $(SRC:.c=.o)

NAME=	  libmlist.a

CFLAGS=	  -W -Werror -Wall -I../../include/ -I./

AR=	  @ar rc

RAN=	  @ranlib

all:	  ../$(NAME)

../$(NAME):	$(OBJ)
		$(AR) $(NAME) $(OBJ)
		$(RAN) $(NAME)
		@mv $(NAME) ../

clean:
	  @rm -f $(OBJ)

fclean:		clean
	  @rm -f ../$(NAME)

re:	  fclean all

yo:	  all clean

.c.o:
	  @gcc -c $< -o $@ $(CFLAGS)
