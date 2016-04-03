/*
** init_minishell2.c for init_minishell2 in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Mar 28 15:11:10 2016 David Zeng
** Last update Mon Apr  4 01:12:44 2016 David Zeng
*/

#include "my_fonction.h"

void		exit_clean_env(char **env, int value, char **tab)
{
  int		i;

  i = 0;
  while (env[i] != NULL)
    {
      free(env[i]);
      i = i + 1;
    }
  free(env);
  if (tab != NULL)
    my_free_tab(tab);
  my_putstr("exit\n");
  exit(value);
}

void		show_pipe(t_proc *proc)//DEBUG==========================
{
  t_proc	*tmp;

  tmp = proc;
  while (tmp != NULL)
    {
      my_printf("1) argv:\n%t\n", tmp->argv);
      my_printf("2) redirect:\n%s\n", tmp->redir);
      my_printf("3) name:\n%s\n", tmp->name);
      tmp = tmp->next;
    }
}

void		show_process(t_list *list)//DEBUG=======================
{
  t_node	*node;
  t_proc	*proc;

  node = list->debut;
  while (node != NULL)
    {
      proc = node->data;
      my_printf("\n======PROC======\n");
      show_pipe(proc);
      node = node->next;
    }
}

int		init_minishell2(char **env)
{
  char		*str;
  char		**tab;
  t_list	*list;

  while (42)
    {
      my_printf("$> ");
      if ((str = get_next_line(0)) == NULL)
	exit_clean_env(env, 0, NULL);
      /* if ((tab = my_parsing(str)) != NULL) */
      /* 	{ */
      /* 	  if (my_builtins(tab, &env) != 1) */
      /* 	    my_get_exec(env, tab); */
      /* 	  my_free_tab(tab); */
      /* 	} */
      tab = lexer(str);
      if ((list = parse_command(tab)) != NULL)
	{
	  show_process(list);
	  my_free_all(&list, &free_proc);
	}
    }
  return (0);
}
