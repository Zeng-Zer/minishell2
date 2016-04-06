/*
** fork_status.c for fork_status in /home/zeng_d
**
** Made by
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Apr  7 00:04:22 2016
** Last update Thu Apr  7 00:15:14 2016 
*/

#include "my_fonction.h"

static void	fork_status(void)
{
  int		status;

  wait(&status);
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGSEGV)
	my_put_err("Segmentation fault\n");
      else if (WTERMSIG(status) == SIGFPE)
	my_put_err("Floating point exception\n");
      else if (WTERMSIG(status) == SIGABRT)
	my_put_err("Aborted\n");
    }
}

void		wait_child_proc(int max)
{
  int		i;

  i = 0;
  while (i < max)
    {
      i = i + 1;
      fork_status();
    }
}
