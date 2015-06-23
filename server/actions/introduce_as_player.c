/*
1;2802;0c** introduce_as_player.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/actions
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sun Jun 21 12:32:53 2015 Oscar
** Last update Tue Jun 23 07:40:17 2015 Oscar
*/

#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<strings.h>
#include	"server.h"

void		pnw_to_all(t_game *data, t_player *player)
{
  t_graphix	*tmp;

  tmp = data->cameras;
  while (tmp != NULL)
    {
      gfx_pnw(data, tmp, player->fd);
      tmp = tmp->next;
    }
}

void		return_map_dimensions(t_game *data, int fd)
{
  char		msg[56];

  bzero(msg, sizeof(char) * 56);
  sprintf(msg, "%d %d\n", data->map_size_x, data->map_size_y);
  write(fd, msg, strlen(msg));
}

void		return_free_slots(int slots, int fd)
{
  char		msg[56];

  bzero(msg, sizeof(char) * 56);
  sprintf(msg, "%d\n", slots);
  write(fd, msg, strlen(msg));
}

int		introduce_as_player(t_game *data, char *arg, int fd)
{
  t_player	*player;
  int		team_id;
  int	        free_slots;
  
  if ((team_id = get_team_id(data, arg)) == 0)
      return (err_ko(fd));
  if ((free_slots = team_get_free_slots(data, team_id)) == 0)
    return (err_ko(fd));
  if ((player = add_client_to_players(data, fd)) == NULL)
    return (-1);
  player->team_id = team_id;
  team_add_slot(data, player->team_id);
  if (finish_player_init(data, player) == -1)
    return (-1);
  return_free_slots(free_slots, fd);
  return_map_dimensions(data, fd);
  pnw_to_all(data, player);
  return (0);
}
