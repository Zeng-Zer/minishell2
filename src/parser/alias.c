/*
** alias.c for alias in /home/zeng_d/test/test
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sat Apr  9 22:50:04 2016 David Zeng
** Last update Sun Apr 10 00:18:33 2016 David Zeng
*/

#include "my_fonction.h"

static char	**replace_cmd(char **cmd, char **replace)
{
  char		**new;
  int		i;
  int		j;

  i = 0;
  j = 0;
  new = MALLOC(sizeof(char *) * (my_tablen(cmd) + my_tablen(replace) + 1));
  while (replace[i] != NULL)
    {
      new[j] = my_strdup(replace[i]);
      j = j + 1;
      i = i + 1;
    }
  i = 1;
  while (cmd[i] != NULL)
    {
      new[j] = my_strdup(cmd[i]);
      j = j + 1;
      i = i + 1;
    }
  new[j] = NULL;
  my_free_tab(cmd);
  return (new);
}

static void	check_replace_alias(t_proc *proc, t_list *alias)
{
  t_node	*tmp;

  tmp = alias->debut;
  while (tmp != NULL)
    {
      if (my_strcmp(proc->argv[0], ((t_alias *)tmp->data)->cmd) == 0)
	{
	  proc->argv = replace_cmd(proc->argv, ((t_alias*)tmp->data)->replace);
	  return;
	}
      tmp = tmp->next;
    }
}

static void	check_alias_cmd(t_proc *proc, t_list *alias)
{
  t_proc	*tmp;

  tmp = proc;
  while (tmp != NULL)
    {
      check_replace_alias(tmp, alias);
      tmp = tmp->next;
    }
}

void		replace_alias(t_list *list, t_list *alias)
{
  t_node	*tmp_list;

  tmp_list = list->debut;
  while (tmp_list != NULL)
    {
      check_alias_cmd(tmp_list->data, alias);
      tmp_list = tmp_list->next;
    }
}
