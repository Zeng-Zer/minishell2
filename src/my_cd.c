/*
** my_cd.c for cd in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Jan  7 01:09:05 2016 David Zeng
** Last update Fri Jan 22 02:40:03 2016 David Zeng
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"
#include "my_list.h"
#include "my_fonction.h"

char		*my_get_lenv(t_list *env, char *elem)
{
  t_node	*tmp;
  char		*str;

  tmp = env->debut;
  while (tmp != NULL)
    {
      str = tmp->data;
      if (my_strncmp(str, elem, my_strlen(elem) - 1) == 0 &&
	  str[my_strlen(elem)] == '=')
	return (&str[my_strlen(elem) + 1]);
      tmp = tmp->next;
    }
  return (NULL);
}

void		my_chdir_chwd(char *path, t_list *env)
{
  char		**tab;

  if ((tab = malloc(sizeof(char *) * 4)) == NULL ||
      (tab[0] = my_strdup("setenv")) == NULL ||
      (tab[1] = my_strdup("OLDPWD")) == NULL)
    return ;
  tab[2] = getcwd(NULL, 0);
  chdir(path);
  tab[3] = NULL;
  my_setenv(tab, env);
  my_free_tab(tab);
  if ((tab = malloc(sizeof(char *) * 4)) == NULL ||
      (tab[0] = my_strdup("setenv")) == NULL ||
      (tab[1] = my_strdup("PWD")) == NULL)
    return ;
  tab[2] = getcwd(NULL, 0);
  tab[3] = NULL;
  my_setenv(tab, env);
  my_free_tab(tab);
}

int		my_go_to_dir(char *path, t_list *env)
{
  struct stat	buf;

  if (stat(path, &buf) == -1)
    {
      my_put_err("cd: ");
      my_put_err(path);
      my_put_err(": No such file or directory\n");
      return (-1);
    }
  if ((buf.st_mode & S_IFMT) == S_IFDIR && access(path, R_OK) == 0)
    my_chdir_chwd(path, env);
  else if ((buf.st_mode & S_IFMT) == S_IFDIR && access(path, R_OK) != 0)
    {
      my_put_err("cd: ");
      my_put_err(path);
      my_put_err(": Permission denied\n");
    }
  else if ((buf.st_mode & S_IFMT) != S_IFDIR)
    {
      my_put_err("cd: ");
      my_put_err(path);
      my_put_err(": Not a directory\n");
    }
  return (0);
}

int		my_check_cd_minus(char *path, t_list *env)
{
  char		*oldpwd;

  if (my_strcmp(path, "-") != 0)
    my_go_to_dir(path, env);
  else
    {
      if ((oldpwd = my_get_lenv(env, "OLDPWD")) != NULL)
	{
	  my_go_to_dir(oldpwd, env);
	}
      else
	my_go_to_dir("", env);
    }
  return (0);
}

int		my_cd(char **tab, t_list *env)
{
  if (my_strcmp(tab[0], "cd") != 0)
    return (0);
  if (my_tablen(tab) > 2)
    {
      my_put_err("USAGE: cd [PATH]\n");
      return (1);
    }
  else if (my_tablen(tab) == 1)
    {
      my_chdir_chwd(my_get_lenv(env, "HOME"), env);
    }
  else
    {
      my_check_cd_minus(tab[1], env);
    }
  return (1);
}
