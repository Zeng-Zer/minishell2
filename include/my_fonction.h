/*
** my_fonction.h :D
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Mon Nov 30 15:49:28 2015 David Zeng
** Last update Sun Apr 10 00:50:23 2016 David Zeng
*/

#ifndef MY_FONCTION_H_
# define MY_FONCTION_H_

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "my.h"
# include "my_list.h"

# define true 1
# define false 0
# define MALLOC malloc_err
# define PUTS(STR) my_printf("%s\n", STR);

typedef struct	s_proc
{
  struct s_proc	*next;
  char		**argv;
  char		in[3];
  char		out[3];
  char		name_in[512];
  char		name_out[512];
}		t_proc;

typedef struct	s_alias
{
  char		*cmd;
  char		**replace;
}		t_alias;

typedef struct	s_use
{
  t_list	*list;
  t_list	*alias;
}		t_use;

int		init_minishell2(char **env);
char		**convert_env(char **env);
void		exit_clean_env(char **env, int value, char **tab, t_use *use);
char		**my_str_to_tab(char *str);
char		**my_tabdup(char **src);
char		**my_parsing(char *str);
int		my_builtins(char **tab, char ***env, int opt, t_use *use);
char		*my_get_env(char **env, char *name);
int		get_ref_env(char **env, char *name);
int		my_setenv(char **tab, char ***env, t_use *use);
int		env_cmp(char **tab, char *env);
int		my_cd(char **tab, char ***env, t_use *use);
int		my_check_exec(char *path);
int		my_get_exec(char **env, char **tab);
t_list		*my_str_to_list(char *str, int c);
void		my_get_builtins_reference(int (*builtins[])(char **,
							    char ***,
							    t_use *));
char		**lexer(char *str);
t_list		*parse_command(char **tab);
int		free_process(t_proc *proc);
void		free_proc(t_proc *proc);
int		parser_cond_redir(char **tab, int i, int max);
int		add_redir(t_proc *act, char **tab, int *i, int max);
int		add_cmd(t_proc *act, char **tab, int i, int max);
void		lexer_token(t_list *list, char *str, int *i);
void		exec_process(t_list *list, char ***env, t_use *use);
int		parse_redirection(t_list *list);
int		redir_proc(t_proc *proc);
int		pipe_nbr(t_proc *proc);
void		dup_and_close_pipe(t_proc *proc, int fd[], int cmd_atm, int max);
void		wait_child_proc(int max);
int		invalid_command(t_proc *proc);
t_list		*new_alias_list(void);
void		replace_alias(t_list *list, t_list *alias);

#endif /* !MY_FONCTION_H_ */
