/*
** action_droite.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:20:37 2015 Oscar Morizet
** Last update Tue Jun 23 08:19:03 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"server.h"

int		action_droite(t_game *data, t_player *player_data, char *arg)
{
  (void) data;
  (void) arg;
  player_data->orientation = (player_data->orientation + 1) % 4;
  write(player_data->fd, "ok\n", 3);
  ppo_to_all(data, player_data);
  return (0);
}
