/*
** action_voir.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:21:15 2015 Oscar Morizet
** Last update Fri Jun 19 18:20:16 2015 Oscar
*/

#include		<stdlib.h>
#include		<string.h>
#include		"server.h"

char			*dump_line(int index, t_game *data,
				   t_coords *coords_tmp, t_orientation orientation)
{
  int			i;
  char			*dump;
  char			*tmp;

  i = 0;
  if ((dump = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  dump[0] = 0;
  while (i != (index * 2) + 1)
    {
      if ((tmp = dump_case(data->map[coords_tmp->y]
			   [coords_tmp->x], index)) == NULL)
	return (NULL);
      dump = realloc(dump, sizeof(char) * (strlen(dump) + strlen(tmp) + 2));
      if (!dump)
	return (NULL);
      strcat(dump, tmp);
      if (i + 1 != (index * 2) + 1)
	strcat(dump, ",");
      if (index)
	move_perpendicular(coords_tmp, orientation);
      make_round(coords_tmp, data->map_size_x, data->map_size_y);
      ++i;
    }
  return (dump);
}

char			*read_perpendicular(t_coords *coords, int index,
					    t_player *player_data, t_game *data)
{
  int			i;
  t_coords		coords_tmp;
  t_orientation		orientation;
  char			*dump;

  i = 0;
  coords_tmp = *coords;
  orientation = player_data->orientation;
  get_perpendicular_begin(&coords_tmp, index, orientation);
  make_round(&coords_tmp, data->map_size_x, data->map_size_y);
  if ((dump = dump_line(index, data, &coords_tmp, orientation)) == NULL)
    return (NULL);
  return (dump);
}

char			*trace_route(t_game *data, t_map_case ***map,
				     t_player *player_data)
{
  int			i;
  char			*vision;
  char			*dumped_line;
  t_coords		coords;

  i = 0;
  coords.x = player_data->x;
  coords.y = player_data->y;
  if ((vision = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  while (i != player_data->level + 1)
    {
      if ((dumped_line = read_perpendicular(&coords, i,
					    player_data, data)) == NULL)
	return (NULL);
      vision = realloc(vision, sizeof(char) * (strlen(vision)
					       + strlen(dumped_line) + 2));
      if (!vision)
	return (NULL);
      strcat(vision, dumped_line);
      ++i;
      trace_move(&coords, player_data->orientation);
      make_round(&coords, data->map_size_x, data->map_size_y);
    }
  return (vision);
}

int			action_voir(t_game *data, t_player *player_data, char *arg)
{
  char			*vision;
  char			*final;

  player_data->level = 1;
  if ((vision = trace_route(data, data->map, player_data)) == NULL)
    return (-1);
  if ((final = malloc(sizeof(char) * (strlen(vision) + 3))) == NULL)
    return (-1);
  sprintf(final, "{%s}\n", vision);
  write(player_data->fd, final, strlen(final));
  return (0);
}
