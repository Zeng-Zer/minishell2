/*
** exec_builtins.c for exec_builtins in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Mar 31 03:22:28 2016 David Zeng
** Last update Thu Apr  7 03:04:07 2016 David Zeng
*/

#include "my_fonction.h"

static void	my_get_builtins_reference_str(char *ref[])
{
  ref[0] = "exit";
  ref[1] = "env";
  ref[2] = "setenv";
  ref[3] = "unsetenv";
  ref[4] = "cd";
}

int		my_builtins(char **tab, char ***env, int opt)
{
  int		(*builtins[5])(char **, char ***);
  char		*reference[5];
  int		i;

  i = 0;
  my_get_builtins_reference(builtins);
  my_get_builtins_reference_str(reference);
  while (i < 5)
    {
      if (my_strcmp(tab[0], reference[i]) == 0)
	{
	  if (opt == true)
	    builtins[i](tab, env);
	  return (1);
	}
      i = i + 1;
    }
  return (0);
}
