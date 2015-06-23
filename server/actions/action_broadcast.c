/*
1;2802;0c** action_broadcast.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:19:54 2015 Oscar Morizet
** Last update Tue Jun 23 12:32:51 2015 Oscar
*/

#include	<stdlib.h>
#include	<math.h>
#include	<unistd.h>
#include	<string.h>
#include	"server.h"

void		pbc_to_all(t_game *data,
			   t_player *player, char *msg)
{
  t_graphix	*tmp;
  char		str_fd[56];

  bzero(str_fd, 56);
  tmp = data->cameras;
  while (tmp != NULL)
    {
      gfx_pbc(data, tmp, player->fd, msg);
      tmp = tmp->next;
    }
}

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
  pbc_to_all(data, player_data, arg);
  return (0);
}
