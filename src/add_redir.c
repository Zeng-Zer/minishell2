/*
** add_redir.c for add_redir in /home/zeng_d/rendu/Shell/PSU_2015_minishell2
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Apr  3 22:14:53 2016 David Zeng
** Last update Mon Apr  4 01:04:33 2016 David Zeng
*/

#include "my_fonction.h"

int		add_redir(t_proc *act, char **tab, int *i, int max)
{
  if (parser_cond_redir(tab, *i + 1, max) == 0)
    {
      my_put_err("Missing name for redirect.\n");
      return (-1);
    }
  if (act->argv == NULL && parser_cond_redir(tab, *i + 2, max) == 0)
    {
      my_put_err("Invalid null command.\n");
      return (-1);
    }
  my_strcpy(act->redir, tab[*i]);
  my_strcpy(act->name, tab[*i + 1]);
  *i = *i + 1;
  return (0);
}

int		add_cmd(t_proc *act, char **tab, int i, int max)
{
  int		j;

  j = 0;
  if (act->argv == NULL)
    {
      act->argv = MALLOC(sizeof(char *) * (max + 1));
      act->argv[0] = NULL;
    }
  while (act->argv[j] != NULL)
    j = j + 1;
  act->argv[j] = my_strdup(tab[i]);
  if (act->argv[j] == NULL)
    exit(1);
  act->argv[++j] = NULL;
  return (0);
}
