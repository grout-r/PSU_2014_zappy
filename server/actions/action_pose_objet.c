/*
** action_pose_objet.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:23:08 2015 Oscar Morizet
** Last update Fri Jun 19 18:20:29 2015 Oscar
*/

#include	<stdlib.h>
#include	"server.h"

int		action_pose_objet(t_game *data, t_player *player_data, char *arg)
{
  t_object     	object;

  object = get_inventory_name_enumed(data, arg);
  if (object == PLAYER || object == NONE)
    {
      write(player_data->fd, "ko\n", 3);
      return (1);
    }
  if (check_object_presence_in_inventory(player_data, arg))
    {
      add_map_case_element(&(data->map[player_data->y][player_data->x]), object);
      change_item_qt(player_data, arg, '-');
      write(player_data->fd, "ok\n", 3);
      return (0);
    }
  write(player_data->fd, "ko\n", 3);
  return (1);
}
