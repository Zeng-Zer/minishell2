/*
** pipe_nbr.c for  in /home/zeng_d/rendu/Shell/PSU_2015_minishell2
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Apr  7 03:05:30 2016 David Zeng
** Last update Thu Apr  7 03:05:31 2016 David Zeng
*/

#include "my_fonction.h"

int		pipe_nbr(t_proc *proc)
{
  int		i;

  i = 0;
  while (proc != NULL)
    {
      i = i + 1;
      proc = proc->next;
    }
  return (i);
}

void		dup_and_close_pipe(t_proc *proc, int fd[], int cmd_atm, int max)
{
  int		i;

  i = 0;
  if (cmd_atm != 0)
    dup2(fd[(cmd_atm - 1) * 2], 0);
  if (proc->next != NULL)
    dup2(fd[cmd_atm * 2 + 1], 1);
  while (i < max * 2)
    {
      close(fd[i]);
      i = i + 1;
    }
}
