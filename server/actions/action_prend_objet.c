/*
** action_prend_objet.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:21:49 2015 Oscar Morizet
** Last update Mon Jun 22 19:17:58 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"server.h"

int		action_prend_objet(t_game *data, t_player *player_data, char *arg)
{
  t_map_case	*map_case;
  t_object     	object;

  object = get_inventory_name_enumed(data, arg);
  if (object == PLAYER || object == NONE)
    {
      write(player_data->fd, "ko\n", 3);
      return (1);
    }
  map_case = data->map[player_data->y][player_data->x];
  if (check_object_presence_in_map_case(map_case, object))
    {
      remove_map_case_element(&(data->map[player_data->y][player_data->x]), object);
      change_item_qt(player_data, arg, '+');
      if (object == NOURRITURE)
	player_data->cycles_to_die += FOOD_CONSUMING_CYCLE;
      write(player_data->fd, "ok\n", 3);
      return (0);
    }
  write(player_data->fd, "ko\n", 3);
  return (1);
}
