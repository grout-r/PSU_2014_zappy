/*
** action_avance.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:15:14 2015 Oscar Morizet
** Last update Mon May 11 17:15:08 2015 Oscar Morizet
*/

#include		<stdlib.h>
#include		"server.h"

int			action_avance(t_game *data, t_player *player_data, char *arg)
{
  t_orientation		orient;

  orient = player_data->orientation;
  printf("position %d %d\n", player_data->x, player_data->y);
  if (orient == LEFT)
    --player_data->x;
  else if (orient == UP)
    ++player_data->y;
  else if (orient == RIGHT)
    ++player_data->x;
  else if (orient == DOWN)
    --player_data->y;
  printf("position %d %d\n", player_data->x, player_data->y);
  return (0);
}
