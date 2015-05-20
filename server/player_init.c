/*
** player_init.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 17:08:21 2015 Oscar Morizet
** Last update Wed May 20 14:50:47 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"

void		gen_position(t_game *game_data, int *x, int *y)
{
  *x = rand() % game_data->map_size_x;
  *y = rand() % game_data->map_size_y;
}

void		init_player(t_game *game_data, t_player *player)
{
  int		x;
  int		y;

  gen_position(game_data, &x, &y);
  player->orientation = UP;
  player->x = x;
  player->y = y;
}
