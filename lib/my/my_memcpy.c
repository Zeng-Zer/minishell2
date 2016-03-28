/*
** my_memcpy.c for my_memcpy in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Mar 28 14:04:39 2016 David Zeng
** Last update Mon Mar 28 14:26:59 2016 David Zeng
*/

#include "my.h"

void		*my_memcpy(void *dest, const void *src, size_t len)
{
  size_t	i;
  char		*dst;
  const char	*tmp;

  i = 0;
  dst = dest;
  tmp = src;
  while (i < len)
    {
      dst[i] = tmp[i];
      i = i + 1;
    }
  return (dest);
}
