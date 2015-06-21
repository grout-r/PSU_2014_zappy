/*
** introduce.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 25 16:10:14 2015 Oscar Morizet
** Last update Sun Jun 21 06:40:31 2015 Oscar
*/

#include	<string.h>
#include	<stdlib.h>
#include	<strings.h>
#include	"server.h"

void		return_map_dimensions(t_game *data, t_player *player)
{
  char		msg[56];

  bzero(msg, sizeof(char) * 56);
  sprintf(msg, "%d %d\n", data->map_size_x, data->map_size_y);
  write(player->fd, msg, strlen(msg));
}

void		return_free_slots(int slots, t_player *player)
{
  char		msg[56];

  bzero(msg, sizeof(char) * 56);
  sprintf(msg, "%d\n", slots);
  write(player->fd, msg, strlen(msg));
}

int		introduce(t_game *data, t_player *player_data, char *arg)
{
  int		team_id;
  int	        free_slots;

  if ((team_id = get_team_id(data, arg)) == 0)
      return (err_no_team(player_data));
  if ((free_slots = team_get_free_slots(data, team_id)) == 0)
    return (err_no_slots_in_team(player_data));
  player_data->team_id = team_id;
  team_add_slot(data, player_data->team_id);
  if (finish_player_init(data, player_data) == -1)
    return (-1);
  return_free_slots(free_slots, player_data);
  return_map_dimensions(data, player_data);
  player_data->introduced = 1;
  return (0);
}
