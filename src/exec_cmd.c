/*
** my_get_env.c for get env in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan  5 21:55:42 2016 David Zeng
** Last update Mon Mar 28 22:10:08 2016 David Zeng
*/

#include "my_fonction.h"

static int	my_fork_exec(char *path, char **env, char **tab)
{
  pid_t		pid;
  int		status;

  pid = fork();
  if (pid == 0)
    {
      execve(path, tab, env);
      exit(0);
    }
  else if (pid > 0)
    {
      wait(&status);
      if (WIFSIGNALED(status))
	{
	  if (WTERMSIG(status) == SIGSEGV)
	    my_printf("Segmentation fault\n");
	  else if (WTERMSIG(status) == SIGFPE)
	    my_printf("Floating point exception\n");
	  else if (WTERMSIG(status) == SIGABRT)
	    my_printf("Aborted\n");
	}
    }
  else
    return (-1);
  return (0);
}

static int	my_exec(char *path, char **tab, char **env)
{
  path = my_reaalloc(path, my_strlen(tab[0]) + 2);
  if (path[my_strlen(path) - 1] != '/')
    my_strcat(path, "/");
  my_strcat(path, tab[0]);
  if (my_check_exec(path) == 0 && access(path, X_OK) == 0)
    {
      if (my_fork_exec(path, env, tab) == -1)
	{
	  my_put_err(tab[0]);
	  my_put_err(" execution failed\n");
	  free(path);
	  return (1);
	}
      free(path);
      return (1);
    }
  free(path);
  return (0);
}

static int	my_local_exec(char **tab, char **env)
{
  if (my_check_exec(tab[0]) == 0 && access(tab[0], X_OK) == 0)
    {
      if (my_fork_exec(tab[0], env, tab) == -1)
	{
	  my_put_err(tab[0]);
	  my_put_err(" execution failed\n");
	  return (1);
	}
      return (1);
    }
  return (0);
}

int		my_get_exec(char **env, char **tab)
{
  int		i;
  int		debut;
  char		*path;

  i = -1;
  debut = 0;
  if ((path = my_get_env(env, "PATH")) != NULL && tab[0][0] != '.')
    {
      while (path[++i] != 0)
	{
	  if (path[i] == ':')
	    {
	      if (my_exec(my_strndup(&path[debut], i - debut), tab, env) == 1)
		return (1);
	      debut = i + 1;
	    }
	}
      if (my_exec(my_strndup(&path[debut], i - debut), tab, env) == 1)
	return (1);
    }
  if (my_local_exec(tab, env) == 1)
    return (1);
  my_put_err(tab[0]);
  my_put_err(": command not found\n");
  return (0);
}
