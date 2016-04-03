/*
** free_process.c for free_process in /home/zeng_d/rendu/Shell/PSU_2015_minishell2
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Apr  3 20:49:14 2016 David Zeng
** Last update Sun Apr  3 23:05:28 2016 David Zeng
*/

#include "my_fonction.h"

int		free_process(t_proc *proc)
{
  t_proc	*tmp;
  t_proc	*tmp_free;

  tmp = proc;
  while (tmp != NULL)
    {
      tmp_free = tmp;
      tmp = tmp->next;
      my_free_tab(tmp_free->argv);
      free(tmp_free);
    }
  return (-1);
}

void		free_proc(t_proc *proc)
{
  t_proc	*tmp;
  t_proc	*tmp_free;

  tmp = proc;
  while (tmp != NULL)
    {
      tmp_free = tmp;
      tmp = tmp->next;
      my_free_tab(tmp_free->argv);
      free(tmp_free);
    }
}
