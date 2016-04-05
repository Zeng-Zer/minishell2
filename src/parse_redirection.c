/*
** parse_redirection.c for parse_redirection in /home/zeng_d/rendu/AI/dante/generator
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Apr  6 01:38:50 2016 David Zeng
** Last update Wed Apr  6 01:44:35 2016 David Zeng
*/

#include "my_fonction.h"

static int	parse_pipe_redirection(t_proc *proc)
{
  t_proc	*prev;

  prev = NULL;
  while (proc != NULL)
    {
      if (proc->in[0] != 0 && prev != NULL)
	{
	  my_put_err("Ambiguous input redirect.\n");
	  return (-1);
	}
      else if (proc->out[0] != 0 && proc->next != NULL)
	{
	  my_put_err("Ambiguous output redirect.\n");
	  return (-1);
	}
      prev = proc;
      proc = proc->next;
    }
  return (0);
}

int		parse_redirection(t_list *list)
{
  t_node	*tmp;

  tmp = list->debut;
  while (tmp != NULL)
    {
      if (parse_pipe_redirection(tmp->data) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}
