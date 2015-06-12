/*
1;2802;0c** execute.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May  4 23:42:32 2015 Oscar Morizet
** Last update Fri Jun 12 23:07:00 2015 Oscar
*/

#include	<stdlib.h>
#include	"server.h"

t_player	*get_player_data(t_game *game_data, int fd)
{
  t_player	*tmp;

  tmp = game_data->players;
  while (tmp != NULL)
    {
      if (tmp->fd == fd)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int		execute(t_game *game_data, int req_fd, char *buffer)
{
  t_command	cm;
  t_player	*player_data;
  char		*extra;

  player_data = get_player_data(game_data, req_fd);
  if (player_data->introduced == 1)
    {
      if ((cm = get_command(game_data, buffer)) == INVALID)
	return (1);
      extra = get_command_argument(buffer);
      printf("Command %d argument %s\n", cm, extra); 
      if (add_new_task_to_queue(game_data, player_data, cm, extra) == -1)
	return (-1);
    }
  else
    {
      if (introduce(game_data, player_data, buffer) == -1)
	return (-1);
    }
  return (0);
}
