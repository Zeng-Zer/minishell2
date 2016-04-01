##
## Makefile for mklib in /home/zeng_d/usefull/my_lib/source
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Sun Oct 11 14:33:50 2015 David Zeng
## Last update Fri Apr  1 15:20:26 2016 David Zeng
##

SRC=	  my_getnbr.c \
	  my_get_dbl.c \
	  my_getnbr_err.c \
          my_putchar.c \
          my_put_nbr.c \
          my_putstr.c \
          my_revstr.c \
          my_strcat.c \
          my_strcmp.c \
	  my_strncmp.c \
          my_strcpy.c \
	  my_strncpy.c \
          my_strlen.c \
	  my_strdup.c \
	  my_strndup.c \
	  my_show_tab.c \
	  my_tablen.c \
	  my_free_tab.c \
	  my_put_err.c \
	  get_next_line.c \
	  my_getnbr_base.c \
	  my_memset.c \
	  my_memcpy.c \
	  malloc_err.c \
	  my_realloc.c \
	  my_testnbr.c \
	  printf/my_printf.c \
	  printf/disp_stdarg.c \
	  printf/my_print.c \
	  printf/my_print2.c \
	  printf/my_print3.c \
	  printf/my_printS.c \
	  use/my_sputchar.c \
	  use/my_sputstr.c \
	  use/my_sput_nbr.c \
	  use/my_sshow_tab.c \
	  sprintf/my_sprintf.c \
	  sprintf/disp_sprintf.c \
	  sprintf/my_sprint.c \
	  sprintf/my_sprint2.c \
	  sprintf/my_sprint3.c \
	  sprintf/my_sprintS.c \

NAME=	  libmy.a

LIB=	  ../$(NAME)

OBJ=	  $(SRC:.c=.o)

INC=	  -I../../include/ -I./

CFLAGS=	  -W -Werror -Wall

AR=	  ar rc

RAN=	  ranlib

all:	  $(LIB)

$(LIB):	  $(OBJ)
	  @$(AR) $(NAME) $(OBJ)
	  @$(RAN) $(NAME) && $(ECHONAME)
	  @mv $(NAME) ../

clean:
	  @rm -f $(OBJ) && $(ECHOCLEAN)

fclean:	  clean
	  @rm -f $(LIB) && $(ECHOFCLEAN)

re:	  fclean all

yo:	  all
	  @rm -f $(OBJ)

.c.o:
	  @gcc -c $< -o $@ $(INC) $(CFLAGS) && $(ECHOOBJ)

## HIDDEN
DEFAULT	  = "\033[00m"
GREEN	  = "\033[0;32m"
TEAL	  = "\033[1;36m"
RED	  = "\033[0;31m"

ECHONAME  = echo -e $(GREEN)"[BIN]" $(TEAL) $(NAME) $(DEFAULT) || \
	    echo -e $(RED)"[XX]" $(TEAL) $(NAME) $(DEFAULT)

ECHOOBJ	  = echo -e $(GREEN)"[OK] " $(TEAL) $< $(DEFAULT) || \
	    echo -e $(RED)"[XX]" $(TEAL) $< $(DEFAULT)

ECHOCLEAN = echo -e $(RED)"[DELETED]" $(TEAL) "*.o" $(DEFAULT)

ECHOFCLEAN= echo -e $(RED)"[DELETED]" $(TEAL) $(NAME) $(DEFAULT)
