/*
** init_alias.c for init_alias in /home/zeng_d/test/test
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Apr  9 23:54:38 2016 David Zeng
** Last update Mon Apr 11 19:06:48 2016 David Zeng
*/

#include "my_fonction.h"

static void	delete_old_alias(t_list *alias, char *cmd)
{
  t_node	*node;
  t_node	*tmp;

  node = alias->debut;
  while (node != NULL)
    {
      tmp = node;
      node = node->next;
      if (my_strcmp(((t_alias *)tmp->data)->cmd, cmd) == 0)
	{
	  free(((t_alias *)tmp->data)->cmd);
	  my_free_tab(((t_alias *)tmp->data)->replace);
	  my_del_node(alias, tmp);
	}
    }
}

void		new_alias(t_list *alias, char *cmd, char **replace)
{
  t_alias	*new;

  new = MALLOC(sizeof(t_alias));
  if ((new->cmd = my_strdup(cmd)) == NULL ||
      (new->replace = my_tabdup(replace)) == NULL)
    exit(1);
  delete_old_alias(alias, cmd);
  my_add_list(alias, new);
}

t_list		*new_alias_list(void)
{
  t_list	*alias;

  if ((alias = my_declare_list()) == NULL)
    exit(1);
  return (alias);
}
