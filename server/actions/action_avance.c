/*
** action_avance.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:15:14 2015 Oscar Morizet
** Last update Fri Jun 19 17:59:50 2015 Oscar
*/

#include		<stdlib.h>
#include		"server.h"

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
  if (move_player_to(data, player_data, new_x, new_y) == -1)
    return (-1);
  dump_map(data);
  write(player_data->fd, "ok\n", 3);
  return (0);
}
