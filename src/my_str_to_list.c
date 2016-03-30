/*
** my_str_to_list.c for my_str_to_list in /home/zeng_d/test/test
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Mar 30 22:17:20 2016 David Zeng
** Last update Wed Mar 30 22:25:11 2016 David Zeng
*/

#include "my_fonction.h"

t_list		*my_str_to_list(char *str, int c)
{
  t_list	*list;
  int		i;
  int		deb;
  char		*tmp;

  if ((list = my_declare_list()) == NULL)
    exit(1);
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] != 0 && str[i] != c)
	{
	  deb = i;
	  while (str[i] != 0 && str[i] != c)
	    i = i + 1;
	  if ((tmp = my_strndup(&str[deb], i - deb)) == NULL)
	    exit(1);
	  my_add_list(list, tmp);
	}
      if (str[i] != 0)
	i = i + 1;
    }
  return (list);
}
