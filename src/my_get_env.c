/*
** my_get_env.c for my_get_env in /home/zeng_d/rendu/Shell/PSU_2015_minishell2
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Mar 28 19:59:15 2016 David Zeng
** Last update Mon Mar 28 21:58:28 2016 David Zeng
*/

#include "my_fonction.h"

char		*my_get_env(char **env, char *name)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], name, my_strlen(name)) == 0)
	return (&env[i][my_strlen(name)]);
      i = i + 1;
    }
  return (NULL);
}

int		get_ref_env(char **env, char *name)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], name, my_strlen(name)) == 0)
	return (i);
      i = i + 1;
    }
  return (-1);
}

int		env_cmp(char **tab, char *env)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (my_strncmp(tab[i], env, my_strlen(tab[i])) == 0 &&
	  env[my_strlen(tab[i])] == '=')
	return (1);
      i = i + 1;
    }
  return (0);
}
