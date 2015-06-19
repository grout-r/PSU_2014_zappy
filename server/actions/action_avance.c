/*
** action_avance.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:15:14 2015 Oscar Morizet
** Last update Fri Jun 19 19:09:26 2015 Oscar
*/

#include		<stdlib.h>
#include		"server.h"

void			globify(t_game *data, int *x, int *y)
{
  if (*x < 0)
    *x = data->map_size_x - 1;
  else if (*x > data->map_size_x - 1)
    *x = 0;
  if (*y < 0)
    *y = data->map_size_y - 1;
  else if (*y > data->map_size_y - 1)
    *y = 0;
}

int			action_avance(t_game *data, t_player *player_data, char *arg)
{
  t_orientation		orient;
  int			new_x;
  int			new_y;

  new_x = player_data->x;
  new_y = player_data->y;
  orient = player_data->orientation;
  if (orient == LEFT)
    --new_x;
  else if (orient == UP)
    --new_y;
  else if (orient == RIGHT)
    ++new_x;
  else if (orient == DOWN)
    ++new_y;
  globify(data, &new_x, &new_y);
  if (move_player_to(data, player_data, new_x, new_y) == -1)
    return (-1);
  dump_map(data);
  write(player_data->fd, "ok\n", 3);
  return (0);
}
