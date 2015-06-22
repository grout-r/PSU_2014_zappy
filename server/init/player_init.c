/*
** player_init.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 17:08:21 2015 Oscar Morizet
** Last update Mon Jun 22 08:28:46 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"server.h"

int		finish_player_init(t_game *game_data, t_player *player)
{
  int		x;
  int		y;

  x = rand() % game_data->map_size_x;
  y = rand() % game_data->map_size_y;
  player->x = x;
  player->y = y;
  if (add_map_case_element(&(game_data->map[player->y][player->x]),
			   PLAYER) == -1)
    return (-1);
  return (0);
}

int		init_player(t_game *game_data, t_player *player)
{
  (void) game_data;
  player->level = 1;
  player->inventory = NULL;
  if (init_inventory(player) == -1)
    return (-1);
  if (init_player_exec_line(player) == -1)
    return (-1);
  player->orientation = UP;
  return (0);
}
