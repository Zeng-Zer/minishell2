/*
** convert_env.c for convert_env in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Mar 28 15:21:49 2016 David Zeng
** Last update Mon Mar 28 15:32:41 2016 David Zeng
*/

#include "my_fonction.h"

char		**convert_env(char **env)
{
  char		**new;
  int		i;

  if ((new = malloc(sizeof(char*) * (my_tablen(env) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (env[i] != NULL)
    {
      new[i] = my_strdup(env[i]);
      i = i + 1;
    }
  new[i] = NULL;
  return (new);
}
