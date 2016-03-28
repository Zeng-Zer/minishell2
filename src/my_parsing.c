/*
** my_parsing.c for parsing in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Jan  4 23:07:07 2016 David Zeng
** Last update Mon Mar 28 15:47:01 2016 David Zeng
*/

#include "my_fonction.h"

static char	*my_cut_space(char *str)
{
  int		i;
  char		*new;

  i = 0;
  while ((str[i] == ' ' || str[i] == '\t') && str[i] != 0)
    i = i + 1;
  if (my_strlen(&str[i]) + 1 == 1)
    {
      free(str);
      return (NULL);
    }
  if ((new = malloc(sizeof(char) *(my_strlen(&str[i]) + 1))) == NULL)
    return (NULL);
  my_strcpy(new, &str[i]);
  i = my_strlen(new) - 1;
  while (i != 0 && (new[i] == ' ' || new[i] == '\t'))
    {
      i = i - 1;
    }
  i = i + 1;
  new[i] = '\0';
  free(str);
  return (new);
}

char		**my_parsing(char *str)
{
  char		**tab;
  char		*new;

  if (my_strcmp(str, "") == 0)
    {
      free(str);
      return (NULL);
    }
  if ((new = my_cut_space(str)) == NULL)
    return (NULL);
  tab = my_str_to_tab(new);
  if (tab == NULL || tab[0] == NULL)
    return (NULL);
  return (tab);
}
