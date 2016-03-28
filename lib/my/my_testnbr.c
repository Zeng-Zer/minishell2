/*
** my_testnbr.c for my_testnbr in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Mar 28 16:04:38 2016 David Zeng
** Last update Mon Mar 28 16:34:26 2016 David Zeng
*/

#include "my.h"

int		my_testnbr(char *str, int *nb)
{
  char		buffer[my_strlen(str) + 10];
  int		tmp;

  if (nb == NULL)
    {
      tmp = my_getnbr(str);
      my_sprintf(buffer, "%d", tmp);
      if (my_strcmp(str, buffer) == 0)
	return (1);
    }
  *nb = my_getnbr(str);
  my_sprintf(buffer, "%d", *nb);
  if (my_strcmp(str, buffer) == 0)
    return (1);
  return (0);
}
