/*
** runtime_tools.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sat Jun  6 11:23:08 2015 Oscar
** Last update Tue Jun 23 08:56:31 2015 Oscar
*/

#include		<sys/select.h>
#include		<sys/time.h>
#include		<stdio.h>
#include		<unistd.h>
#include		"server.h"
#include		"timer.h"

void			set_standby_clients(t_server_info *server, t_game *game_data)
{
  t_standby_client    	*tmp;

  tmp = game_data->standby_clients;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, server->fd_reads);
      if (tmp->fd > server->fd_max)
	server->fd_max = tmp->fd;
      tmp = tmp->next;
    }
}

void			set_players(t_server_info *server, t_game *game_data)
{
  t_player		*tmp;

  tmp = game_data->players;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, server->fd_reads);
      if (tmp->fd > server->fd_max)
	server->fd_max = tmp->fd;
      tmp = tmp->next;
    }
}

void			set_cameras(t_server_info *server, t_game *game_data)
{
  t_graphix		*tmp;

  tmp = game_data->cameras;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, server->fd_reads);
      if (tmp->fd > server->fd_max)
	server->fd_max = tmp->fd;
      tmp = tmp->next;
    }
}

void			reset_sets(t_server_info *server, t_game *game_data)
{
  FD_ZERO(server->fd_reads);
  FD_SET(server->server_fd, server->fd_reads);
  server->fd_max = server->server_fd;
  set_standby_clients(server, game_data);
  set_players(server, game_data);
  set_cameras(server, game_data);
}
