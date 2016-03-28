/*
** my_show_list.c for show list in /home/zeng_d/test/fonctions
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Oct 20 16:34:50 2015 David Zeng
** Last update Mon Mar 28 01:06:07 2016 David Zeng
*/

#include "my_list.h"

void		my_show_list(t_list *list, char separator)
{
  t_node	*tmp;

  tmp = list->debut;
  while (tmp != NULL)
    {
      my_putstr(tmp->data);
      if (tmp->next != NULL)
	my_putchar(separator);
      tmp = tmp->next;
    }
}
