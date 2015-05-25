/*
** player_init.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 17:08:21 2015 Oscar Morizet
** Last update Mon May 25 15:55:02 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"

void		gen_position(t_game *game_data, int *x, int *y)
{
  *x = rand() % game_data->map_size_x;
  *y = rand() % game_data->map_size_y;
}

void		introduce(t_player *player)
{
  write(player->fd, "BIENVENUE\n", 10); 
}

int		init_player(t_game *game_data, t_player *player)
{
  int		x;
  int		y;

  player->inventory = NULL;
  gen_position(game_data, &x, &y);
  if (init_inventory(player) == -1)
    return (-1);
  player->orientation = UP;
  player->x = x;
  player->y = y;
  introduce(player);
  return (0);
}
