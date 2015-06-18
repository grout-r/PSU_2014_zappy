/*
** action_droite.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:20:37 2015 Oscar Morizet
** Last update Mon May 25 15:41:45 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"

int		action_droite(t_game *data, t_player *player_data, char *arg)
{
  player_data->orientation = (player_data->orientation + 1) % 4;
  printf("P%d turned --> o = %d\n", player_data->fd, player_data->orientation);
  write(player_data->fd, "ok\n", 3);
  return (0);
}
