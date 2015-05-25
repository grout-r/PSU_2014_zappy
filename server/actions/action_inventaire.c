/*
** action_inventaire.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:23:26 2015 Oscar Morizet
** Last update Mon May 25 15:42:10 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	<string.h>
#include	"server.h"

int		action_inventaire(t_game *data, t_player *player_data, char *arg)
{
  char		*content;

  if ((content = list_inventory(player_data)) == NULL)
    return (1);
  write(player_data->fd, content, strlen(content));
  return (0);
}
