/*
** my_builtins.c for builtins in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan  6 22:30:09 2016 David Zeng
** Last update Mon Mar 28 21:54:16 2016 David Zeng
*/

#include "my_fonction.h"

static int	my_env(char **tab, char ***env)
{
  if (my_strcmp(tab[0], "env") != 0)
    return (0);
  if (my_tablen(tab) != 1)
    {
      my_put_err("USAGE: env\n");
      return (1);
    }
  my_printf("%t", *env);
  return (1);
}

static int	my_exit(char **tab, char ***env)
{
  int		exit_value;
  int		tmp;

  exit_value = 0;
  if (my_strcmp(tab[0], "exit") != 0)
    return (0);
  if ((tmp = my_tablen(tab)) != 2 ||
      (tmp == 2 && my_testnbr(tab[1], &exit_value) != 1))
    {
      my_put_err("exit: Expression Syntax\n");
      return (1);
    }
  exit_clean_env(*env, exit_value, tab);
  return (1);
}

static void	tabcpy_unset(char ***new, char **tab, char **env)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (env[i] != NULL)
    {
      if (env_cmp(tab, env[i]) == 0)
	{
	  (*new)[j] = env[i];
	  j = j + 1;
	}
      else
	free(env[i]);
      i = i + 1;
    }
  (*new)[j] = NULL;
  free(env);
}

static int	my_unsetenv(char **tab, char ***env)
{
  char		**new;

  if (my_strcmp(tab[0], "unsetenv") != 0)
    return (0);
  if (my_tablen(tab) == 1)
    {
      my_put_err("unsetenv: Too few arguments.\n");
      return (1);
    }
  if ((new = malloc(sizeof(char *) * (my_tablen(*env) + 1))) == NULL)
    exit(1);
  tabcpy_unset(&new, &tab[1], *env);
  (*env) = new;
  return (1);
}

int		my_builtins(char **tab, char ***env)
{
  int		(*builtins[5])(char **, char ***);
  int		i;

  i = 0;
  builtins[0] = &my_exit;
  builtins[1] = &my_env;
  builtins[2] = &my_setenv;
  builtins[3] = &my_unsetenv;
  builtins[4] = &my_cd;
  while (i < 5)
    {
      if (builtins[i](tab, env) == 1)
	return (1);
      i = i + 1;
    }
  return (0);
}
