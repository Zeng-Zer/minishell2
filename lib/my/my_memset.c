/*
** my_memset.c for my_memset in /home/zeng_d
**
** Made by
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Mar 28 13:56:51 2016
** Last update Mon Mar 28 14:26:05 2016 David Zeng
*/

#include "my.h"

void		*my_memset(void *dest, int c, size_t len)
{
  size_t	i;
  char		*tmp;

  i = 0;
  tmp = dest;
  if (dest == NULL)
    {
      my_printf("Memset null pointer\n");
      return (NULL);
    }
  while (i < len)
    {
      tmp[i] = c;
      i = i + 1;
    }
  return (dest);
}
