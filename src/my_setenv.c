/*
** my_setenv.c for my_setenv in /home/zeng_d/rendu/Shell/PSU_2015_minishell2
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Mar 28 18:00:42 2016 David Zeng
** Last update Mon Mar 28 21:28:08 2016 David Zeng
*/

#include "my_fonction.h"

static char	**my_tabcpy(char **dest, char **src)
{
  int		i;

  i = 0;
  while (src[i] != NULL)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = NULL;
  return (dest);
}

static void 	create_env(char **tab, char ***env)
{
  char		**new;
  char		*str;
  int		size;

  if ((new = malloc(sizeof(char *) * ((size = my_tablen(*env)) + 2))) == NULL ||
      (str = malloc(sizeof(char) * my_strlen(tab[0]) + my_strlen(tab[1]) + 3))
      == NULL)
    exit(1);
  my_tabcpy(new, *env);
  my_strcpy(str, tab[0]);
  my_strcat(str, "=");
  if (tab[1] != NULL)
    my_strcat(str, tab[1]);
  new[size] = str;
  new[size + 1] = NULL;
  free(*env);
  *env = new;
}

static void	append_env(char **tab, char ***env, int i)
{
  char		*str;
  char		*tmp;

  if ((str = malloc(sizeof(char) * (my_strlen(tab[0]) + my_strlen(tab[1]) + 3)))
      == NULL)
    exit(1);
  my_strcpy(str, tab[0]);
  my_strcat(str, "=");
  if (tab[1] != NULL)
    my_strcat(str, tab[1]);
  tmp = (*env)[i];
  (*env)[i] = str;
  free(tmp);
}

static void	change_env(char **tab, char ***env)
{
  int		i;
  char		buffer[my_strlen(tab[0]) + 2];

  if (tab[0][0] != '_' && (tab[0][0] < 'a' || tab[0][0] > 'z') &&
      (tab[0][0] < 'A' || tab[0][0] > 'Z'))
    {
      my_printf("setenv: Variable name must begin with a letter\n");
      return;
    }
  my_strcpy(buffer, tab[0]);
  my_strcat(buffer, "=");
  if ((i = get_ref_env(*env, buffer)) == -1)
    create_env(tab, env);
  else
    append_env(tab, env, i);
}

int		my_setenv(char **tab, char ***env)
{
  int		tmp;

  if (my_strcmp(tab[0], "setenv") != 0)
    return (0);
  else if ((tmp = my_tablen(tab)) > 3)
    {
      my_put_err("setenv: Too many arguments.\n");
      return (1);
    }
  if (tmp == 1)
    {
      my_printf("%t", *env);
      return (1);
    }
  else
    change_env(&tab[1], env);
  return (1);
}
