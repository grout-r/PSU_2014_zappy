/*
** action_broadcast.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:19:54 2015 Oscar Morizet
** Last update Tue Jun 23 11:20:08 2015 Oscar
*/

#include	<stdlib.h>
#include	<math.h>
#include	<unistd.h>
#include	<string.h>
#include	"server.h"

void		path_xy(int *src, int dest, int size)
{
  if (*src == dest)
    return;
  if (*src < dest)
    {
      if (dest - *src > size / 2)
	*src -= 1;
      else
	*src += 1;
    }
  else if (*src > dest)
    {
      if (*src - dest > size / 2)
	*src += 1;
      else
	*src -= 1;
    }
  if (*src == -1)
    *src = size - 1;
  if (*src == size)
    *src = 0;
}

int		fill_orient(t_orientation orient, int tab[4], t_orientation from)
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

int    	find_case(int *prev_case, t_player *dest, t_game *data)
{
  int	tab[4];

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

int	find_path(t_game *data, t_player *src, t_player *dest)
{
  int	src_x;
  int	src_y;
  int	pos[2];
  int	i = 0;

  src_x = src->x;
  src_y = src->y;
  pos[0] = src_x;
  pos[1] = src_y;
  while (src_x != dest->x || src_y != dest->y)
    {
      pos[0] = src_x;
      pos[1] = src_y;
      if (i % 2)
	path_xy(&src_x, dest->x, data->map_size_x);
      else
	path_xy(&src_y, dest->y, data->map_size_y);
      ++i;
    }
  return (find_case(pos, dest, data));
}

int		action_broadcast(t_game *data, t_player *player_data,
				 char *arg)
{
  t_player	*players;
  char		*str;

  players = data->players;
  while (players != NULL)
    {
      if (player_data->fd != players->fd)
	{
	  if ((str = malloc(sizeof(char) * (strlen(arg) + 11))) == NULL)
	    return (-1);
	  sprintf(str, "message %d,%s\n",
		  find_path(data, player_data, players), arg);
	  write(players->fd, str, strlen(str));
	  free(str);
	}
      players = players->next;
    }
  return (0);
}
