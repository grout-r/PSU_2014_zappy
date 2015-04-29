/*
** tools.c for zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue Apr 28 21:22:41 2015 Oscar Morizet
** Last update Tue Apr 28 21:23:17 2015 Oscar Morizet
*/

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
