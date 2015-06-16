/*
** action_prend_objet.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:21:49 2015 Oscar Morizet
** Last update Tue Jun 16 14:35:58 2015 Jordan Verove
*/

#include	<stdlib.h>
#include	"server.h"

int		action_prend_objet(t_game *data, t_player *player_data, char *arg)
{
  printf("action prend objet\n");
  while (player_data->inventory->next != NULL)
    {
      if (strcmp(player_data->inventory->name, arg) == 0)
        {
          change_item_qt(player_data, arg, '+');
          return (0);
        }
      player_data->inventory->next++;
    }
  return (0);
}
