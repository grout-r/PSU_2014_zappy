/*
1;2802;0c** execute.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May  4 23:42:32 2015 Oscar Morizet
** Last update Mon Jun 22 11:21:35 2015 Oscar
*/

#include	<stdlib.h>
#include	"server.h"

int		execute_player_request(t_game *game_data,
				       char *buffer, t_player *player_data)
{
  t_command	cm;
  char		*extra;

  if ((cm = get_command(game_data, buffer)) == INVALID)
    {
      return (1);
    }
  extra = get_command_argument(buffer);
  if (add_new_task_to_queue(game_data, player_data, cm, extra) == -1)
    return (-1);
  return (0);
}

int		execute_graphical_request(t_game *game_data,
				       char *buffer, t_graphix *client)
{
  t_gfx_command	cm;
  char		*extra;

  if ((cm = get_gfx_command(game_data, buffer)) == SUC)
    {
      gfx_suc(game_data, client, NULL);
      return (1);
    }
  extra = get_command_argument(buffer);
  if ((game_data->gfx_command_action[cm])
      (game_data, client, extra) == -1)
    return (-1);
  return (0);
}
