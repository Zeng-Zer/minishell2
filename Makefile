##
## Makefile for Makefile in /home/zeng_d/test/10/test
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Mon Oct 12 13:31:18 2015 David Zeng
## Last update Fri Apr  8 22:41:29 2016 David Zeng
##

SRC	= src/main.c \
	  src/init_minishell2.c \
	  src/parser/my_parsing.c \
	  src/parser/lexer.c \
	  src/parser/parse_command.c \
	  src/parser/lexer_token.c \
	  src/parser/parse_redirection.c \
	  src/parser/add_redir.c \
	  src/execution/exec_builtins.c \
	  src/execution/exec_process.c \
	  src/execution/my_check_exec.c \
	  src/execution/exec_cmd.c \
	  src/execution/fork_status.c \
	  src/redirect/pipe_nbr.c \
	  src/redirect/redir_proc.c \
	  src/env/convert_env.c \
	  src/env/my_get_env.c \
	  src/builtins/my_builtins.c \
	  src/builtins/my_cd.c \
	  src/builtins/my_setenv.c \
	  src/misc/my_str_to_tab.c \
	  src/misc/my_str_to_list.c \
	  src/misc/free_process.c \

NAME	= mysh

LIB	= ./lib/libmy.a

LIST	= ./lib/libmlist.a

CC	= gcc

OBJ	= $(SRC:.c=.o)

CFLAGS	= -g -W -Werror -Wall \
	  -Wno-unused-variable \
	  -Wno-unused-parameter \
	  -fms-extensions

INC	= -L./lib -lmlist -lmy -I./include/

PATH1	= ./lib/my/

PATH2	= ./lib/mlist/

all: 	  $(LIB) $(LIST) $(NAME)

$(NAME):  $(OBJ)
	  @$(CC) -o $(NAME) $(OBJ) $(INC) $(CFLAGS) && $(ECHONAME)

$(LIB):
	  @$(MAKE) -C $(PATH1) yo

$(LIST):
	  @$(MAKE) -C $(PATH2) yo

clean:
	  @rm -f $(OBJ) && $(ECHOCLEAN)

fclean:	  clean
	  @rm -f $(NAME) && $(ECHOFCLEAN)

re:	  fclean all

.PHONY:	  all clean fclean re

yo:	  all
	  @rm -f $(OBJ)

.c.o:
	  @$(CC) -c $< -o $@ $(INC) $(CFLAGS) && $(ECHOOBJ)

## HIDDEN
DEFAULT	  = "\033[00m"
GREEN	  = "\033[0;32m"
TEAL	  = "\033[1;36m"
RED	  = "\033[0;31m"

ECHONAME  = echo -e $(GREEN)"[BIN]" $(TEAL) $(NAME) $(DEFAULT) || \
	    echo -e $(RED)"[XX]" $(TEAL) $(NAME) $(DEFAULT)

ECHOOBJ	  = echo -e $(GREEN)"[OK] " $(TEAL) $< $(DEFAULT) || \
	    echo -e $(RED)"[XX]" $(TEAL) $< $(DEFAULT)

ECHOCLEAN = echo -e $(RED)"[DELETED]" $(TEAL)$(OBJ) $(DEFAULT)

ECHOFCLEAN= echo -e $(RED)"[DELETED]" $(TEAL)$(NAME) $(DEFAULT)
