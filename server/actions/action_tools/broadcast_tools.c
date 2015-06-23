/*
** broadcast_tools.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Tue Jun 23 12:26:11 2015 Oscar
** Last update Tue Jun 23 12:28:21 2015 Oscar
*/

#include	<stdlib.h>
#include	"server.h"

int		fill_orient(t_orientation orient,
			    int tab[4], t_orientation from)
{
  if (orient == LEFT)
    {
      tab[LEFT] = 1;
      tab[UP] = 7;
      tab[RIGHT] = 5;
      tab[DOWN] = 3;
    }
  else if (orient == UP)
    {
      tab[LEFT] = 3;
      tab[UP] = 1;
      tab[RIGHT] = 7;
      tab[DOWN] = 5;
    }
  else if (orient == DOWN)
    {
      tab[LEFT] = 7;
      tab[UP] = 5;
      tab[RIGHT] = 3;
      tab[DOWN] = 1;
    }
  return (tab[from]);
}

int		find_case(int *prev_case,
			  t_player *dest, t_game *data)
{
  int		tab[4];

  tab[LEFT] = 5;
  tab[UP] = 3;
  tab[RIGHT] = 1;
  tab[DOWN] = 7;
  if (prev_case[0] != dest->x)
    {
      if (prev_case[0] == (dest->x + 1) % data->map_size_x)
	return (fill_orient(dest->orientation, tab, RIGHT));
      else
	return (fill_orient(dest->orientation, tab, LEFT));
    }
  else if (prev_case[1] != dest->y)
    {
      if (prev_case[1] == (dest->y + 1) % data->map_size_y)
	return (fill_orient(dest->orientation, tab, UP));
      else
	return (fill_orient(dest->orientation, tab, DOWN));
    }
  return (0);
}
