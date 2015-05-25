/*
** execute.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May  4 23:42:32 2015 Oscar Morizet
** Last update Mon May 25 15:39:05 2015 Oscar Morizet
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

  extra = NULL;
  if ((cm = get_command(game_data, buffer)) == INVALID)
    return (1);
  player_data = get_player_data(game_data, req_fd);
  game_data->command_action[cm](game_data, player_data, extra);
  return (0);
}
