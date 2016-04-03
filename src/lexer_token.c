/*
** lexer_token.c for lexer_token in /home/zeng_d/rendu/Shell/PSU_2015_minishell2
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Apr  3 22:57:43 2016 David Zeng
** Last update Sun Apr  3 22:59:20 2016 David Zeng
*/

#include "my_fonction.h"

void		lexer_token(t_list *list, char *str, int i)
{
  if (str[i] == '|')
    my_add_list(list, my_strdup("|"));
  else if (str[i] == ';')
    my_add_list(list, my_strdup(";"));
  else if (str[i] == '>' && str[i + 1] == '>' && str[i + 2] != '>' &&
	   !(i != 0 && str[i - 1] == '>'))
    my_add_list(list, my_strdup(">>"));
  else if (str[i] == '>' && str[i + 1] != '>' &&
	   !(i != 0 && str[i - 1] == '>'))
    my_add_list(list, my_strdup(">"));
  else if (str[i] == '<' && str[i + 1] == '<' && str[i + 2] != '<' &&
	   !(i != 0 && str[i - 1] == '<'))
    my_add_list(list, my_strdup("<<"));
  else if (str[i] == '<' && str[i + 1] != '<' &&
	   !(i != 0 && str[i - 1] == '<'))
    my_add_list(list, my_strdup("<"));
}
