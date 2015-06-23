/*
** server_interactions.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May  4 15:49:46 2015 Oscar Morizet
** Last update Tue Jun 23 13:46:22 2015 Oscar
*/

#include		<sys/select.h>
#include		<sys/types.h>
#include		<strings.h>
#include		<unistd.h>
#include		"server.h"

int			manage_standby_client_request(t_server_info *server,
						      t_game *game_data, int req_fd)
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
      remove_standby_client(game_data, req_fd);
      return (0);
    }
  clean_out_buffer(buffer);
  if (introduce(game_data, buffer, req_fd) == -1)
    return (-1);
  return (0);
}

int			manage_player_request(t_server_info *server,
					  t_game *game_data, int req_fd)
{
  t_player		*player;
  char			buffer[BUFFER_R_SIZE + 1];
  int			ret;

  bzero(buffer, BUFFER_R_SIZE);
  ret = recv(req_fd, buffer, BUFFER_R_SIZE, 0);
  if (ret == -1)
    return (-1);
  player = get_player_data(game_data, req_fd);
  if (ret == 0)
    {
      FD_CLR(req_fd, server->fd_reads);
      remove_map_case_element(&(game_data->map[player->y][player->x]),
			      PLAYER);
      if (remove_client_from_players(game_data, req_fd) == -1)
	return (-1);
      team_free_slot(game_data, player->team_id);
      return (0);
    }
  clean_out_buffer(buffer);
  if (execute_player_request(game_data, buffer, player) == -1)
    return (-1);
  return (0);
}

int			manage_camera_request(t_server_info *server,
					      t_game *game_data, int req_fd)
{
  t_graphix		*client;
  char			buffer[BUFFER_R_SIZE + 1];
  int			ret;

  bzero(buffer, BUFFER_R_SIZE);
  ret = recv(req_fd, buffer, BUFFER_R_SIZE, 0);
  if (ret == -1)
    return (-1);
  client = get_camera_data(game_data, req_fd);
  if (ret == 0)
    {
      FD_CLR(req_fd, server->fd_reads);
      if (remove_client_from_cameras(game_data, req_fd) == -1)
	return (-1);
      return (0);
    }
  clean_out_buffer(buffer);
  if (execute_graphical_request(game_data, buffer, client) == -1)
    return (-1);
  return (0);
}

int			handle_server_requests(t_server_info *server,
					      t_game *game_data)
{
  if (FD_ISSET(server->server_fd, server->fd_reads))
    {
      if (accept_new_client(server, game_data) == -1)
	return (-1);
    }
  if (handle_player_requests(server, game_data) == -1)
    return (-1);
  if (handle_camera_requests(server, game_data) == -1)
    return (-1);
  if (handle_anonymous_requests(server, game_data) == -1)
    return (-1);
  return (0);
}
