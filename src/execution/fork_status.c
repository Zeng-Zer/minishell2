/*
** fork_status.c for  in /home/zeng_d/rendu/Shell/PSU_2015_minishell2
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Apr  7 03:04:25 2016 David Zeng
** Last update Thu Apr  7 03:32:24 2016 David Zeng
*/

#include "my_fonction.h"

static void	fork_status(void)
{
  int		status;

  status = 0;
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
