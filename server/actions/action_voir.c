/*
** action_voir.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:21:15 2015 Oscar Morizet
** Last update Tue May 26 14:52:17 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"

char		*read_perpendicular(t_coords *coords, int index,
				    t_player *player_data, t_game *data)
{
  int		i;
  t_coords	coords_tmp;
  t_orientation	orientation;

  i = 0;
  coords_tmp = *coords;
  orientation = player_data->orientation;
  get_perpendicular_begin(&coords_tmp, index, orientation);
  make_round(&coords_tmp, data->map_size_x, data->map_size_y);
  while (i != (index * 2) + 1)
    {
      printf("[%d] [%d]\n", coords_tmp.x, coords_tmp.y);
      if (index)
	move_perpendicular(&coords_tmp, orientation);
      make_round(&coords_tmp, data->map_size_x, data->map_size_y);
      ++i;
    }
  return (NULL);
}

char		*trace_route(t_game *data, t_map_case ***map,
			     t_player *player_data)
{
  int		i;
  t_coords	coords;

  i = 0;
  coords.x = player_data->x;
  coords.y = player_data->y;
  while (i != player_data->level + 1)
    {
      read_perpendicular(&coords, i, player_data, data);
      ++i;
      trace_move(&coords, player_data->orientation);
      make_round(&coords, data->map_size_x, data->map_size_y);
    }
  return (NULL);
}

int		action_voir(t_game *data, t_player *player_data, char *arg)
{
  char		*vision;

  player_data->orientation = LEFT;
  player_data->x = 0;
  player_data->y = 49;
  player_data->level = 3;
  vision = trace_route(data, data->map, player_data);
  return (0);
}
