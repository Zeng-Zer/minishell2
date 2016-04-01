/*
** lexer.c for lexer in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Apr  1 14:33:33 2016 David Zeng
** Last update Fri Apr  1 16:35:00 2016 David Zeng
*/

#include "my_fonction.h"

static int     lex_cond(char *str, int i, char quote)
{
  if (quote == 0)
    return (str[i] != 0 && str[i] != ' ' && str[i] != '\t' && str[i] != ';' &&
	    str[i] != '|' && str[i] != ';' && str[i] != '>' && str[i] != '<');
  else
    return (str[i] != 0 && str[i] != quote);
}

static int	lexe_str(t_list *list, char *str, int *i)
{
  char		quote;
  int		deb;

  quote = 0;
  if (str[*i] == '\'' || str[*i] == '\"' || str[*i] == '`')
    {
      quote = str[*i];
      *i = *i + 1;
    }
  deb = *i;
  while (lex_cond(str, *i, quote))
    *i = *i + 1;
  if (quote != 0 && str[*i] != quote)
    {
      my_put_err("Missing \", ' or `\n");
      return (-1);
    }
  my_add_list(list, my_strndup(&str[deb], *i - deb));
  if (quote != 0)
    *i = *i + 1;
  return (0);
}

static int	fill_lexer_list(t_list *list, char *str, int i)
{
  while (str[i] != 0)
    {
      while (str[i] != 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == ';' ||
			     str[i] == '|' || str[i] == '>' || str[i] == '<'))
	{
	  if (str[i] == '|')
	    my_add_list(list, my_strdup("|"));
	  else if (str[i] == ';')
	    my_add_list(list, my_strdup(";"));
	  else if (str[i] == '>' && str[i + 1] == '>')
	    my_add_list(list, my_strdup(">>"));
	  else if (str[i] == '>' && !(i != 0 && str[i - 1] == '>'))
	    my_add_list(list, my_strdup(">"));
	  else if (str[i] == '<' && str[i + 1] == '<')
	    my_add_list(list, my_strdup("<<"));
	  else if (str[i] == '<' && !(i != 0 && str[i - 1] == '<'))
	    my_add_list(list, my_strdup("<"));
	  i = i + 1;
	}
      if (str[i] != 0)
	if (lexe_str(list, str, &i) == -1)
	  return (-1);
    }
  return (0);
}

t_list		*lexer(char *str)
{
  t_list	*list;

  if ((list = my_declare_list()) == NULL)
    exit(1);
  if (fill_lexer_list(list, str, 0) == -1)
    {
      my_free_all(&list, &free);
      return (NULL);
    }
  return (list);
}
