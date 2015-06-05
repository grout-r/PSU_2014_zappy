/*
** init.c for zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue Apr 28 18:53:50 2015 Oscar Morizet
** Last update Fri Jun  5 01:13:36 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<netinet/in.h>
#include	<string.h>
#include	<arpa/inet.h>
#include        <netdb.h>
#include	"server.h"

int		init(t_game *game_data, t_server_info *server_info)
{
  init_command_names(game_data);
  init_command_action(game_data);
  if ((server_info->fd_reads = malloc(sizeof(fd_set))) == NULL)
    return (-1);
  if (init_server(server_info) == -1)
    return (-1);
  if (init_map(game_data) == -1)
    return (-1);
  if (init_timer(game_data, server_info) == -1)
    return (-1);
  return (1);
}

int		init_server(t_server_info *server)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;

  pe = getprotobyname("TCP");
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(server->running_port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if ((server->server_fd = socket(AF_INET, SOCK_STREAM,
			  pe->p_proto)) == -1)
    return (-1);
  if (bind(server->server_fd, (const struct sockaddr *)&(s_in),
	   sizeof(s_in)) == -1)
    {
      close(server->server_fd);
      return (-1);
    }
  if (listen(server->server_fd, MAX_CONNECTIONS) == -1)
    return (-1);
  return (0);
}

