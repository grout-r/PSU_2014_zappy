/*
** introduce.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 25 16:10:14 2015 Oscar Morizet
** Last update Mon May 25 17:12:07 2015 Oscar Morizet
*/

#include	<strings.h>
#include	"server.h"

void		print_map_dimensions(t_game *data)
{
  char		dim[56];

  bzero(dim, sizeof(char) * 56);
  sprintf(dim, "%d %d\n", data->map_size_x, data->map_size_y);
}

int		introduce(t_game *data, t_player *player_data, char *arg)
{
  int		team_id;
  int		tmp;

  if ((team_id = get_team_id(data, arg)) == 0)
      return (err_no_team(player_data));
  if ((tmp = team_get_free_slots(data, team_id)) == 0)
    return (err_no_slots_in_team(player_data));
  player_data->team_id = team_id;
  team_add_slot(data, player_data->team_id);
  print_map_dimensions(data);
  player_data->introduced = 1;
  return (0);
}
