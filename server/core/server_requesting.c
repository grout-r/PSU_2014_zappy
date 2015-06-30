/*
** server_requesting.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sun Jun 21 12:52:56 2015 Oscar
** Last update Mon Jun 22 07:29:41 2015 Oscar
*/

#include		<sys/select.h>
#include		<sys/types.h>
#include		<strings.h>
#include		<unistd.h>
#include		"server.h"

int			handle_anonymous_requests(t_server_info *server,
						  t_game *game_data)
{
  t_standby_client	*tmp;

  tmp = game_data->standby_clients;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, server->fd_reads))
	{
	  if (manage_standby_client_request(server,
					    game_data, tmp->fd) == -1)
	    {
	      return (-1);
	    }
	}
      if ((tmp = tmp->next) == NULL)
	return (0);
    }
  return (0);
}

int			handle_player_requests(t_server_info *server,
					       t_game *game_data)
{
  t_player		*tmp;

  tmp = game_data->players;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, server->fd_reads))
	{
	  if (manage_player_request(server,
				    game_data, tmp->fd) == -1)
	    return (-1);
	}
      if ((tmp = tmp->next) == NULL)
	return (0);
    }
  return (0);
}

int			handle_camera_requests(t_server_info *server,
						t_game *game_data)
{
  t_graphix		*tmp;

  tmp = game_data->cameras;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, server->fd_reads))
	{
	  if (manage_camera_request(server,
				    game_data, tmp->fd) == -1)
	    return (-1);
	}
      if ((tmp = tmp->next) == NULL)
	return (0);
    }
  return (0);
}
