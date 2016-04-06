/*
** parse_command.c for parse_command in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Apr  1 19:41:31 2016 David Zeng
** Last update Thu Apr  7 01:43:59 2016 
*/

#include "my_fonction.h"

static t_proc		*new_proc(void)
{
  t_proc		*new;

  new = MALLOC(sizeof(t_proc));
  new->next = NULL;
  new->argv = NULL;
  new->in[0] = 0;
  new->out[0] = 0;
  new->name_in[0] = 0;
  new->name_out[0] = 0;
  return (new);
}

static int		add_pipe(t_proc **proc, int i, int max)
{
  if ((*proc)->argv == NULL || i == max)
    {
      my_put_err("Invalid null command.\n");
      return (-1);
    }
  (*proc)->next = new_proc();
  *proc = (*proc)->next;
  return (0);
}

int			parser_cond_redir(char **tab, int i, int max)
{
  if (max == -1)
    return (my_strcmp(tab[i], "<<") == 0 || my_strcmp(tab[i], ">>") == 0 ||
	    my_strcmp(tab[i], ">") == 0 || my_strcmp(tab[i], "<") == 0);
  return (i != max && my_strcmp(tab[i], "<<") != 0 &&
	  my_strcmp(tab[i], ">>") != 0 && my_strcmp(tab[i], ">") != 0 &&
	  my_strcmp(tab[i], "<") != 0 && my_strcmp(tab[i], "|") != 0);
}

static int		add_cmd_list(t_list *list, char **tab, int max, int i)
{
  t_proc		*proc;
  t_proc		*act;

  proc = new_proc();
  act = proc;
  while (++i < max)
    {
      if (my_strcmp(tab[i], "|") == 0)
	{
	  if (add_pipe(&act, i + 1, max) == -1)
	    return (free_process(proc));
	}
      else if (parser_cond_redir(tab, i, -1))
	{
	  if (add_redir(act, tab, &i, max) == -1)
	    return (free_process(proc));
	}
      else
	add_cmd(act, tab, i, max);
    }
  my_add_list(list, proc);
  return (0);
}

t_list			*parse_command(char **tab)
{
  t_list		*list;
  int			i;
  int			deb;

  if ((list = my_declare_list()) == NULL)
    exit(1);
  i = 0;
  while (tab[i] != NULL)
    {
      deb = i;
      while (tab[i] != NULL && my_strcmp(tab[i], ";") != 0)
	i = i + 1;
      if (add_cmd_list(list, &tab[deb], i - deb, -1) == -1)
	{
	  my_free_all(&list, &free_proc);
	  my_free_tab(tab);
	  return (NULL);
	}
      if (tab[i] != NULL)
	i = i + 1;
    }
  my_free_tab(tab);
  return (list);
}
