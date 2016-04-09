/*
** init_alias.c for init_alias in /home/zeng_d/test/test
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Apr  9 23:54:38 2016 David Zeng
** Last update Sun Apr 10 00:06:21 2016 David Zeng
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

static void	new_alias(t_list *alias, char *cmd, char **replace)
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
  char		*replace[3];

  replace[0] = "ls";
  replace[1] = "--color=auto";
  replace[2] = NULL;
  if ((alias = my_declare_list()) == NULL)
    exit(1);
  new_alias(alias, "ls", replace);
  return (alias);
}
