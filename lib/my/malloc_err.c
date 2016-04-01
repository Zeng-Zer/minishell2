/*
** malloc_err.c for malloc_err in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Apr  1 15:11:10 2016 David Zeng
** Last update Fri Apr  1 15:32:33 2016 David Zeng
*/

#include "my.h"

void	*malloc_err(size_t size)
{
  void	*new;

  if ((new = malloc(size)) == NULL)
    {
      my_put_err("Malloc failed\n");
      __asm__ __volatile__  ("int $0x80"
			     :
			     : "a" (1), "b" (-1)
			     : "memory");
    }
  return (new);
}
