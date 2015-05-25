/*
** server_interactions.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May  4 15:49:46 2015 Oscar Morizet
** Last update Mon May 25 15:38:37 2015 Oscar Morizet
*/

#include		<sys/select.h>
#include		<sys/types.h>
#include		<strings.h>
#include		<unistd.h>
#include		"server.h"

int			handle_req(t_server_info *server, t_game *game_data, int req_fd)
{
  char			buffer[BUFFER_R_SIZE + 1];
  int			ret;

  bzero(buffer, BUFFER_R_SIZE);
  ret = recv(req_fd, buffer, BUFFER_R_SIZE, 0);
  if (ret == -1)
    return (-1);
  if (ret == 0)
    {
      FD_CLR(req_fd, server->fd_reads);
      if (remove_client_from_players(game_data, req_fd) == -1)
	return (-1);
    }
  clean_out_buffer(buffer);
  if (execute(game_data, req_fd, buffer) == -1)
    return (-1);
  return (0);
}

int			add_new_client(t_server_info *server, t_game *game_data)
{
  int                   client_fd;
  struct sockaddr_in    client_sin;
  socklen_t             client_sin_len;

  client_sin_len = sizeof(struct sockaddr *);
  if ((client_fd = accept(server->server_fd,
                              (struct sockaddr *)&client_sin,
                              &client_sin_len)) == -1)
    return (-1);
  if (add_client_to_players(game_data, client_fd) == -1)
    return (-1);
  return (0);
}

int			handle_server_interactions(t_server_info *server,
						   t_game *game_data)
{
  t_player		*tmp;

  tmp = game_data->players;
  if (FD_ISSET(server->server_fd, server->fd_reads))
    {
      if (add_new_client(server, game_data) == -1)
	return (-1);
    }
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, server->fd_reads))
	{
	  if (handle_req(server, game_data, tmp->fd) == -1)
	    return (-1);
	}
      if ((tmp = tmp->next) == NULL)
	return (0);
    }
  return (0);
}
