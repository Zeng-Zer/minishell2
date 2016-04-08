/*
** exec_process.c for exec_process in /home/zeng_d/rendu/AI/dante/generator
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Apr  5 21:54:14 2016 David Zeng
** Last update Sat Apr  9 00:50:03 2016 David Zeng
*/

#include "my_fonction.h"

static void	pipe_and_close(int fd[], int max, int opt)
{
  int		i;

  i = 0;
  if (opt == 1)
    {
      while (i < max)
	{
	  pipe(&fd[i * 2]);
	  i = i + 1;
	}
    }
  else
    {
      while (i < max * 2)
	{
	  close(fd[i]);
	  i = i + 1;
	}
    }
}

static void	exec_pipe_proc(t_proc *proc, char ***env, int *fd, int cmd_atm)
{
  if (redir_proc(proc, fd, &cmd_atm) != -1)
    {
      if (my_builtins(proc->argv, env, true) != 1)
	my_get_exec(*env, proc->argv);
    }
  exit(1);
}

static void	handle_pipe(t_proc *proc, char ***env, int max)
{
  int		cmd_atm;
  int		fd[max * 2];
  int		pid;

  pipe_and_close(fd, max, 1);
  cmd_atm = 0;
  while (proc != NULL && !(proc->next == NULL &&
			   my_builtins(proc->argv, env, false) == 1))
    {
      if ((pid = fork()) == -1)
	return (my_put_err("Fork failed.\n"));
      else if (pid == 0)
	{
	  dup_and_close_pipe(proc, fd, cmd_atm, max);
	  exec_pipe_proc(proc, env, fd, cmd_atm);
	}
      proc = proc->next;
      cmd_atm = cmd_atm + 1;
    }
  if (proc != NULL && proc->next == NULL && my_builtins(proc->argv, env, 0) == 1)
    my_builtins(proc->argv, env, true);
  pipe_and_close(fd, max, 0);
  wait_child_proc(max);
}

void		exec_process(t_list *list, char ***env)
{
  t_node	*tmp;

  tmp = list->debut;
  while (tmp != NULL)
    {
      handle_pipe(tmp->data, env, pipe_nbr(tmp->data));
      tmp = tmp->next;
    }
}
