/*
** my_tabdup.c for my_tabdup in /home/zeng_d/test/test
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Apr  9 23:37:55 2016 David Zeng
** Last update Sat Apr  9 23:39:53 2016 David Zeng
*/

#include "my_fonction.h"

char		**my_tabdup(char **src)
{
  int		i;
  char		**tab;

  i = 0;
  tab = MALLOC(sizeof(char *) * (my_tablen(src) + 1));
  while (src[i] != NULL)
    {
      if ((tab[i] = my_strdup(src[i])) == NULL)
	exit(1);
      i = i + 1;
    }
  tab[i] = NULL;
  return (tab);
}
