/*
** execute.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May  4 23:42:32 2015 Oscar Morizet
** Last update Sun Jun 21 13:37:51 2015 Oscar
*/

#include	<stdlib.h>
#include	"server.h"

int		execute_player_request(t_game *game_data,
				       char *buffer, t_player *player_data)
{
  t_command	cm;
  char		*extra;

  if ((cm = get_command(game_data, buffer)) == INVALID)
    return (1);
  extra = get_command_argument(buffer);
  if (add_new_task_to_queue(game_data, player_data, cm, extra) == -1)
    return (-1);
}
