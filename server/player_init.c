/*
** player_init.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 17:08:21 2015 Oscar Morizet
** Last update Mon May 25 17:12:21 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"

void		print_welcome(t_player *player)
{
  player->introduced = 0;
  write(player->fd, "BIENVENUE\n", 10);
}

int		finish_player_init(t_game *game_data, t_player *player)
{
  int		x;
  int		y;

  x = rand() % game_data->map_size_x;
  y = rand() % game_data->map_size_y;
  player->x = x;
  player->y = y;
  if (add_map_case_element(&(game_data->map[player->y][player->x]),
			   player->fd) == -1)
  move_player_to(game_data, player, player->x, player->y);
}

int		init_player(t_game *game_data, t_player *player)
{
  player->inventory = NULL;
  if (init_inventory(player) == -1)
    return (-1);
  player->orientation = UP;
  print_welcome(player);
  return (0);
}
