/*
** my_get_env.c for get env in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan  5 21:55:42 2016 David Zeng
** Last update Thu Apr  7 02:35:18 2016 
*/

#include "my_fonction.h"

static int	my_fork_exec(char *path, char **env, char **tab)
{
  execve(path, tab, env);
  return (0);
}

static int	my_exec(char *path, char **tab, char **env)
{
  char		buffer[my_strlen(path) + my_strlen(tab[0]) + 3];

  my_strcpy(buffer, path);
  if (buffer[my_strlen(buffer) - 1] != '/')
    my_strcat(buffer, "/");
  my_strcat(buffer, tab[0]);
  if (my_check_exec(buffer) == 0 && access(buffer, X_OK) == 0)
    {
      if (my_fork_exec(buffer, env, tab) == -1)
	{
	  my_put_err(tab[0]);
	  my_put_err(" execution failed\n");
	}
      return (1);
    }
  return (0);
}

static int	my_local_exec(char **tab, char **env)
{
  if (tab[0][0] != '.' && tab[0][0] != '/')
    return (0);
  if (my_check_exec(tab[0]) == 0 && access(tab[0], X_OK) == 0)
    {
      my_fork_exec(tab[0], env, tab);
      return (1);
    }
  return (0);
}

int		my_get_exec(char **env, char **tab)
{
  char		*path;
  t_list	*list;
  t_node	*node;

  if ((path = my_get_env(env, "PATH=")) != NULL && tab[0][0] != '.')
    {
      list = my_str_to_list(path, ':');
      node = list->debut;
      while (node != NULL)
	{
	  if (my_exec(node->data, tab, env) == 1)
	    {
	      my_free_all(&list, &free);
	      return (1);
	    }
	  node = node->next;
	}
      my_free_all(&list, &free);
    }
  if (my_local_exec(tab, env) == 1)
    return (1);
  my_put_err(tab[0]);
  my_put_err(": Command not found.\n");
  return (0);
}
