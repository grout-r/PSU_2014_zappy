/*
** tools.c for zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue Apr 28 21:22:41 2015 Oscar Morizet
** Last update Mon May  4 23:24:10 2015 Oscar Morizet
*/

#include	<string.h>

void			clean_out_buffer(char *str)
{
  int		size;

  size = strlen(str);
  while (size >= 0)
    {
      if (str[size] == '\n')
	{
	  str[size] = '\0';
	  if (str[size - 1] == '\r')
	    str[size - 1] = '\0';
	  return ;
	}
      --size;
    }
}

int		check_if_num(char *str)
{
  while (*str)
    {
      if (*str < '0' || *str > '9')
	return (0);
      ++str;
    }
  return (1);
}
