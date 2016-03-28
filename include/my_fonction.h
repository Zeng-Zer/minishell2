/*
** my_fonction.h :D
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov 30 15:49:28 2015 David Zeng
** Last update Mon Mar 28 19:52:55 2016 David Zeng
*/

#ifndef MY_FONCTION_H_
# define MY_FONCTION_H_

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include "my.h"
# include "my_list.h"

int		init_minishell2(char **env);
char		**convert_env(char **env);
void		exit_clean_env(char **env, int value, char **tab);
char		**my_str_to_tab(char *str);
char		**my_parsing(char *str);
int		my_builtins(char **tab, char **env);

int		my_setenv(char **tab, char **env);

#endif /* !MY_FONCTION_H_ */
