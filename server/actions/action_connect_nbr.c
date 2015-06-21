/*
** action_connect_nbr.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:29:16 2015 Oscar Morizet
** Last update Sun Jun 21 08:47:07 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<strings.h>
#include	"server.h"

int		action_connect_nbr(t_game *data, t_player *player_data, char *arg)
{
  char		free_slots[9];

  bzero(free_slots, 9);
  sprintf(free_slots, "%d\n",
	  team_get_free_slots(data, player_data->team_id));
  write(player_data->fd, free_slots, strlen(free_slots)); 
  return (0);
}
