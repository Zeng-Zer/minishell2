/*
** my_str_to_tab.c for str => tab in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan  5 00:10:27 2016 David Zeng
** Last update Mon Mar 28 15:48:58 2016 David Zeng
*/

#include "my_fonction.h"

static int	my_parse_str(char *str, t_list *list, int *i)
{
  char		c;
  int		debut;
  char		*new;

  if ((c = str[*i]) != 34 && c != 39 && c != 96)
    c = ' ';
  if (c != ' ')
    *i = *i + 1;
  debut = *i;
  while ((str[*i] != 0 && str[*i] != c && str[*i] != '\t' && c == ' ') ||
	 (str[*i] != 0 && str[*i] != c && c != ' '))
    *i = *i + 1;
  if (str[*i] != c && c != ' ' && str[*i] != '\t')
    {
      my_put_err("Missing \", ' or `\n");
      return (-1);
    }
  if ((new = malloc(sizeof(char) * (*i - debut + 1))) == NULL)
    return (-1);
  my_strncpy(new, &str[debut], *i - debut);
  my_add_list(list, new);
  if (c != ' ')
    *i = *i + 1;
  return (0);
}

static int	my_fill_list(char *str, t_list *list)
{
  int		i;

  i = 0;
  while (str[i] != 0)
    {
      while ((str[i] == ' ' || str[i] == '\t') && str[i] != 0)
	i = i + 1;
      if (my_parse_str(str, list, &i) == -1)
	{
	  my_free_all(&list, &free);
	  return (-1);
	}
    }
  return (0);
}

static char	**my_list_to_tab(t_list *list)
{
  t_node	*tmp;
  char		**tab;
  int		i;

  i = 0;
  tmp = list->debut;
  if ((tab = malloc(sizeof(char *) * (list->length + 1))) == NULL)
    return (NULL);
  while (tmp != NULL)
    {
      tab[i] = tmp->data;
      i = i + 1;
      tmp = tmp->next;
    }
  tab[i] = 0;
  return (tab);
}

char		**my_str_to_tab(char *str)
{
  char		**tab;
  t_list	*list;

  if ((list = my_declare_list()) == NULL)
    return (NULL);
  if (my_fill_list(str, list) == -1)
    {
      free(str);
      return (NULL);
    }
  tab = my_list_to_tab(list);
  my_free_list(&list);
  free(str);
  return (tab);
}
