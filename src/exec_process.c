/*
** exec_process.c for exec_process in /home/zeng_d/rendu/AI/dante/generator
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Apr  5 21:54:14 2016 David Zeng
** Last update Tue Apr  5 23:10:38 2016 David Zeng
*/

#include "my_fonction.h"

static void	exec_pipe(t_proc *proc, char ***env)
{
  t_proc	*tmp;

  tmp = proc;
  while (tmp != NULL)
    {
      if (my_builtins(tmp->argv, env, true) != 1)
	my_get_exec(*env, tmp->argv);
      tmp = tmp->next;
    }
}

void		exec_process(t_list *list, char ***env)
{
  t_node	*tmp;

  tmp = list->debut;
  while (tmp != NULL)
    {
      exec_pipe(tmp->data, env);
      tmp = tmp->next;
    }
}
