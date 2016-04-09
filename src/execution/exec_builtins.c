/*
** exec_builtins.c for exec_builtins in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Mar 31 03:22:28 2016 David Zeng
** Last update Sun Apr 10 01:04:05 2016 David Zeng
*/

#include "my_fonction.h"

static void	my_get_builtins_reference_str(char *ref[])
{
  ref[0] = "exit";
  ref[1] = "env";
  ref[2] = "setenv";
  ref[3] = "unsetenv";
  ref[4] = "cd";
  ref[5] = "alias";
}

int		my_builtins(char **tab, char ***env, int opt, t_use *use)
{
  int		(*builtins[6])(char **, char ***, t_use *);
  char		*reference[6];
  int		i;

  i = 0;
  my_get_builtins_reference(builtins);
  my_get_builtins_reference_str(reference);
  while (i < 6)
    {
      if (my_strcmp(tab[0], reference[i]) == 0)
	{
	  if (opt == true)
	    builtins[i](tab, env, use);
	  return (1);
	}
      i = i + 1;
    }
  return (0);
}
