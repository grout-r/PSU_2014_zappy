/*
** action_gauche.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:20:13 2015 Oscar Morizet
** Last update Fri Jun 19 18:46:03 2015 Oscar
*/

#include		<stdlib.h>
#include		"server.h"

int			action_gauche(t_game *data, t_player *player_data, char *arg)
{
  player_data->orientation = (player_data->orientation + 3) % 4;
  write(player_data->fd, "ok\n", 3);
  return (0);
}
