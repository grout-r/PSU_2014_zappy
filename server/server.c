/*
** server.c for zappy in /home/verove_j/rendu/PSU_2014_zappy/server
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Mon May  4 14:19:53 2015 Jordan Verove
** Last update Tue May  5 00:29:08 2015 Oscar Morizet
*/

#include	<sys/select.h>
#include	<stdio.h>
#include	"server.h"

void		reset_sets(t_server_info *server, t_game *game_data)
{
  t_player	*tmp;

  tmp = game_data->players;	
  FD_ZERO(server->fd_reads);
  FD_SET(server->server_fd, server->fd_reads);
  server->fd_max = server->server_fd;
  while (tmp != NULL)
    {
      FD_SET(tmp->player_fd, server->fd_reads);
      if (tmp->player_fd > server->fd_max)
	server->fd_max = tmp->player_fd;
      tmp = tmp->next;
    }
}

int		handle_connection(t_game *game_data, t_server_info *server)
{
  (void) game_data;

  while (42)
    {
      reset_sets(server, game_data);
      if (select(server->fd_max + 1,
		 server->fd_reads, NULL, NULL, NULL) == -1)
	{
	  perror("Select error: ");
	  return (-1);
	}
      handle_server_interactions(server, game_data);
      sleep(1);
    }
  return (0);
}
