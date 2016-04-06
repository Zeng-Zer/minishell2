/*
** pipe_nbr.c for pipe_nbr in /home/zeng_d
**
** Made by
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Apr  6 21:08:42 2016
** Last update Wed Apr  6 23:56:32 2016 
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
