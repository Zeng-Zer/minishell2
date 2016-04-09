/*
** my_alias.c for my_alias in /home/zeng_d/test/test
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Apr 10 01:04:15 2016 David Zeng
** Last update Sun Apr 10 01:23:06 2016 David Zeng
*/

#include "my_fonction.h"

static void	print_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      if (tab[i + 1] != NULL)
	my_putchar(' ');
      i = i + 1;
    }
  my_putchar('\n');
}

static void	print_alias(t_list *alias, char *cmd)
{
  t_node	*tmp;

  tmp = alias->debut;
  while (tmp != NULL)
    {
      if (my_strcmp(cmd, ((t_alias *)tmp->data)->cmd) == 0)
	{
	  print_tab(((t_alias *)tmp->data)->replace);
	  return;
	}
      tmp = tmp->next;
    }
}

int		my_alias(char **tab, char ***env, t_use *use)
{
  (void)env;
  if (my_tablen(tab) == 2)
    {
      print_alias(use->alias, tab[1]);
      return (1);
    }
  else if (my_tablen(tab) > 2)
    new_alias(use->alias, tab[1], &tab[2]);
  return (1);
}
