/*
** my_check_exec.c for check exec in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan  6 21:58:50 2016 David Zeng
** Last update Mon Mar 28 22:08:32 2016 David Zeng
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static int	my_check_slash(char *str)
{
  int		i;
  int		flag;

  flag = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (flag == 1 && str[i] == '/')
	return (-1);
      if (str[i] != '/')
	flag = 0;
      else
	flag = 1;
      i = i + 1;
    }
  return (0);
}

int		my_check_exec(char *path)
{
  struct stat	buf;

  if (my_check_slash(path) == -1)
    return (-1);
  if (stat(path, &buf) == -1)
    return (-1);
  if ((buf.st_mode & S_IFMT) == S_IFREG)
    return (0);
  return (-1);
}
