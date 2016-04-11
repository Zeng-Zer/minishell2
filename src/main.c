/*
** main.c for main in /home/zeng_d/usefull
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Dec 14 14:07:51 2015 David Zeng
** Last update Mon Apr 11 19:01:24 2016 David Zeng
*/

#include "my_fonction.h"

void	my_hand(int sig)
{
  if (sig == SIGINT)
    my_putstr("\n$> ");
}

int	main(int argc, char **argv, char **env)
{
  char	**new;

  if (signal(SIGINT, my_hand) == SIG_ERR ||
      signal(SIGTSTP, my_hand) == SIG_ERR ||
      signal(SIGQUIT, my_hand) == SIG_ERR ||
      signal(SIGTERM, my_hand) == SIG_ERR)
    return (-1);
  if ((new = convert_env(env)) == NULL)
    return (-1);
  init_minishell2(new);
  return (0);
}
