/*
** init_minishell2.c for init_minishell2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Mar 28 15:11:10 2016 David Zeng
** Last update Sun Apr 10 00:57:41 2016 David Zeng
*/

#include "my_fonction.h"

void		free_alias(t_alias *alias)
{
  free(alias->cmd);
  my_free_tab(alias->replace);
  free(alias);
}

void		exit_clean_env(char **env, int value, char **tab, t_use *use)
{
  int		i;

  i = 0;
  (void)tab;
  while (env[i] != NULL)
    {
      free(env[i]);
      i = i + 1;
    }
  free(env);
  my_free_all(&use->alias, &free_alias);
  if (use->list != NULL)
    my_free_all(&use->list, &free_proc);
  my_putstr("exit\n");
  exit(value);
}

void		show_pipe(t_proc *proc)
{
  t_proc	*tmp;

  tmp = proc;
  while (tmp != NULL)
    {
      my_printf("1) argv:\n%t", tmp->argv);
      my_printf("2) in:\n%s\n", tmp->in);
      my_printf("3) name_in:\n%s\n\n", tmp->name_in);
      my_printf("4) out:\n%s\n", tmp->out);
      my_printf("5) name_out:\n%s\n\n", tmp->name_out);
      tmp = tmp->next;
    }
}

void		show_process(t_list *list)
{
  t_node	*node;
  t_proc	*proc;

  node = list->debut;
  while (node != NULL)
    {
      proc = node->data;
      my_printf("======PROC======\n");
      show_pipe(proc);
      node = node->next;
    }
}

int		init_minishell2(char **env)
{
  char		*str;
  t_list	*list;
  t_use		use;

  use.alias = new_alias_list();
  while (42)
    {
      my_printf("$> ");
      use.list = NULL;
      if ((str = get_next_line(0)) == NULL)
	exit_clean_env(env, 0, NULL, &use);
      if ((list = parse_command(lexer(str))) != NULL)
	{
	  if (parse_redirection(list) == 0)
	    {
	      replace_alias(list, use.alias);
	      use.list = list;
	      exec_process(list, &env, &use);
	    }
	  my_free_all(&list, &free_proc);
	}
    }
  my_free_all(&use.alias, &free_alias);
  return (0);
}
