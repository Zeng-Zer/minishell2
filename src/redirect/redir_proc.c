/*
** redir_proc.c for redir_proc in /home/zeng_d/rendu/AI/dante/generator
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Apr  6 01:47:34 2016 David Zeng
** Last update Sat Apr  9 23:44:27 2016 David Zeng
*/

#include "my_fonction.h"

static int	redir_in_double(t_proc *proc)
{
  char		*str;
  int		fd[2];

  pipe(fd);
  my_printf("? ");
  while ((str = get_next_line(0)) != NULL)
    {
      if (my_strcmp(str, proc->name_in) == 0)
	{
	  close(fd[1]);
	  dup2(fd[0], 0);
	  free(str);
	  return (0);
	}
      my_printf("? ");
      write(fd[1], str, my_strlen(str));
      write(fd[1], "\n", 1);
      free(str);
    }
  if (str == NULL)
    return (-1);
  return (0);
}

static int	redir_in(t_proc *proc)
{
  int		fd;

  if (my_strcmp(proc->in, "<") == 0)
    {
      if ((fd = open(proc->name_in, O_RDONLY)) == -1)
	{
	  my_put_err(proc->name_in);
	  my_put_err(": No such file or directory.\n");
	  return (-1);
	}
      dup2(fd, 0);
    }
  else if (my_strcmp(proc->in, "<<") == 0)
    {
      if (redir_in_double(proc) == -1)
	return (-1);
    }
  return (0);
}

static int	redir_out(t_proc *proc)
{
  int		fd;

  if (my_strcmp(proc->out, ">") == 0)
    {
      if ((fd = open(proc->name_out, O_CREAT | O_TRUNC | O_RDWR, 0644)) == -1)
	return (-1);
      dup2(fd, 1);
    }
  else if (my_strcmp(proc->out, ">>") == 0)
    {
      if ((fd = open(proc->name_out, O_CREAT | O_APPEND | O_RDWR, 0644)) == -1)
	return (-1);
      dup2(fd, 1);
    }
  return (0);
}

int		redir_proc(t_proc *proc)
{
  if (proc->in[0] != 0 && redir_in(proc) == -1)
    return (-1);
  if (proc->out[0] != 0 && redir_out(proc) == -1)
    return (-1);
  return (0);
}
