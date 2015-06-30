/*
** graphic_actions_tools.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 09:56:25 2015 Oscar
** Last update Mon Jun 22 11:22:35 2015 Oscar
*/

#include	<stdlib.h>
#include	"server.h"

int		check_bct_parameters(char *arg)
{
  while (*arg && *arg != ' ')
    {
      if (*arg < '0' || *arg > '9')
	return (-1);
      ++arg;
    }
  if (*arg != ' ')
    return (-1);
  ++arg;
  while (*arg)
    {
      if (*arg < '0' || *arg > '9')
	return (-1);
      ++arg;
    }
  return (0);
}

int		get_bct_coords(t_game *data, char *arg, int *x, int *y)
{
  if (check_bct_parameters(arg) == -1)
    return (-1);
  *x = atoi(arg);
  while (*arg != ' ')
    ++arg;
  ++arg;
  *y = atoi(arg);
  if (*x > data->map_size_x || *y > data->map_size_y)
    return (-1);
  return (0);
}
