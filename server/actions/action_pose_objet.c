/*
** action_pose_objet.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:23:08 2015 Oscar Morizet
** Last update Sun Jul  5 15:28:11 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"server.h"

void		pdr_to_all(t_game *data, t_player *player, t_object obj)
{
  t_graphix    	*tmp;

  tmp = data->cameras;
  while (tmp != NULL)
    {
      gfx_pdr(data, tmp, player->fd, ((int) obj) - 1);
      tmp = tmp->next;
    }
}

int		get_less_food_mult(t_game *game, t_player *player)
{
  if (player->cycles_to_die <= FOOD_CONSUMING_CYCLE)
    {
      if (player_dies(game, player) == -1)
	return (-1);
    }
  else
    {
      while ((player->cycles_to_die % 126) != 0)
	--player->cycles_to_die;
    }
  return (0);
}

int		action_pose_objet(t_game *data,
				  t_player *player_data, char *arg)
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
      add_map_case_element(&(data->map[player_data->y]
			     [player_data->x]), object);
      change_item_qt(player_data, arg, '-');
      if (object == NOURRITURE)
	{
	  if (get_less_food_mult(data, player_data) == -1)
	    return (-1);
	}
      pdr_to_all(data, player_data, object);
      write(player_data->fd, "ok\n", 3);
      return (0);
    }
  write(player_data->fd, "ko\n", 3);
  return (1);
}
