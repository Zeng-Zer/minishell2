/*
** my_realloc.c for my_realloc in /home/zeng_d/rendu/Shell/PSU_2015_minishell2
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Mar 28 18:05:29 2016 David Zeng
** Last update Mon Mar 28 19:43:13 2016 David Zeng
*/

#include "my.h"

void		*my_realloc(void *dest, size_t old_size, size_t new_size)
{
  char		*new;

  if (dest == NULL)
    return (malloc(new_size));
  else if (new_size == 0)
    {
      free(dest);
      return (NULL);
    }
  if ((new = malloc(new_size)) == NULL)
    return (NULL);
  my_memcpy(new, dest, old_size);
  free(dest);
  return (new);
}
