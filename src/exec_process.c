/*
** exec_process.c for exec_process in /home/zeng_d/rendu/AI/dante/generator
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Apr  5 21:54:14 2016 David Zeng
** Last update Tue Apr  5 23:38:20 2016 David Zeng
*/

#include "my_fonction.h"

static void	fork_pipe(t_proc *proc, char ***env)
{
  int		pid;
  int		status;

  pid = fork();
  if (pid == 0)
    {
      if (my_builtins(proc->argv, env, true) != 1)
	my_get_exec(*env, proc->argv);
      exit(1);
    }
  else if (pid > 0)
    {
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
  else
    my_put_err("Fork failed.\n");
}

static void	exec_pipe(t_proc *proc, char ***env)
{
  t_proc	*tmp;

  tmp = proc;
  while (tmp != NULL)
    {
      if (my_builtins(tmp->argv, env, false) == 1 && tmp->next == NULL)
	my_builtins(proc->argv, env, true);
      else
	fork_pipe(tmp, env);
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
