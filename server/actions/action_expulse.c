/*
** action_expulse.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:20:58 2015 Oscar Morizet
** Last update Sun Jul  5 15:11:30 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"server.h"

int		action_expulse(t_game *data,
			       t_player *player_data, char *arg)
{
  (void) arg;
  (void) data;
  write(player_data->fd, "ko\n", 3);
  return (0);
}
