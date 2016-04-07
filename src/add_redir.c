/*
** add_redir.c for add_redir in /home/zeng_d/rendu/Shell/PSU_2015_minishell2
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Apr  3 22:14:53 2016 David Zeng
** Last update Thu Apr  7 02:26:55 2016 
*/

#include "my_fonction.h"

int		check_redir(t_proc *act, char **tab, int *i)
{
  if (my_strcmp(tab[*i], ">>") == 0 || my_strcmp(tab[*i], ">") == 0)
    {
      if (act->out[0] != 0)
	{
	  my_put_err("Ambiguous output redirect.\n");
	  return (-1);
	}
      my_strcpy(act->out, tab[*i]);
      my_strcpy(act->name_out, tab[*i + 1]);
    }
  else if (my_strcmp(tab[*i], "<<") == 0 || my_strcmp(tab[*i], "<") == 0)
    {
      if (act->in[0] != 0)
	{
	  my_put_err("Ambiguous input redirect.\n");
	  return (-1);
	}
      my_strcpy(act->in, tab[*i]);
      my_strcpy(act->name_in, tab[*i + 1]);
    }
  return (0);
}

int		add_redir(t_proc *act, char **tab, int *i, int max)
{
  if (parser_cond_redir(tab, *i + 1, max) == 0)
    {
      my_put_err("Missing name for redirect.\n");
      return (-1);
    }
  if (check_redir(act, tab, i) == -1)
    return (-1);
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

int		invalid_command(t_proc *proc)
{
  my_put_err("Invalid null command.\n");
  return (free_process(proc));
}
