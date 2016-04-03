/*
** my_fonction.h :D
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov 30 15:49:28 2015 David Zeng
** Last update Sun Apr  3 22:59:30 2016 David Zeng
*/

#ifndef MY_FONCTION_H_
# define MY_FONCTION_H_

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "my.h"
# include "my_list.h"

# define true 1
# define false 0
# define MALLOC malloc_err

typedef struct	s_proc
{
  struct s_proc	*next;
  char		**argv;
  char		redir[3];
  char		name[512];
}		t_proc;

int		init_minishell2(char **env);
char		**convert_env(char **env);
void		exit_clean_env(char **env, int value, char **tab);
char		**my_str_to_tab(char *str);
char		**my_parsing(char *str);
int		my_builtins(char **tab, char ***env);
char		*my_get_env(char **env, char *name);
int		get_ref_env(char **env, char *name);
int		my_setenv(char **tab, char ***env);
int		env_cmp(char **tab, char *env);
int		my_cd(char **tab, char ***env);
int		my_check_exec(char *path);
int		my_get_exec(char **env, char **tab);
t_list		*my_str_to_list(char *str, int c);
void		my_get_builtins_reference(int (*builtins[])(char **, char ***));
char		**lexer(char *str);
t_list		*parse_command(char **tab);
int		free_process(t_proc *proc);
void		free_proc(t_proc *proc);
int		parser_cond_redir(char **tab, int i, int max);
int		add_redir(t_proc *act, char **tab, int i, int max);
int		add_cmd(t_proc *act, char **tab, int i, int max);
void		lexer_token(t_list *list, char *str, int i);

#endif /* !MY_FONCTION_H_ */
