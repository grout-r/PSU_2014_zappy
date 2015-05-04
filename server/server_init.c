/*
** server.c for zappy in /home/verove_j/rendu/PSU_2014_zappy/server
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Mon May  4 09:51:37 2015 Jordan Verove
** Last update Mon May  4 10:09:06 2015 Jordan Verove
*/

#include <unistd.h>

#include "server.h"

int		init_socket(t_server_info *server, int port)
{
  server->pe = getprotobyname("TCP");
  server->s_in.sin_family = AF_INET;
  server->s_in.sin_port = htons(port);
  server->s_in.sin_addr.s_addr = INADDR_ANY;
  if ((server->server_fd = socket(AF_INET, SOCK_STREAM, server->pe->p_proto)) == -1)
    return (-1);
  return (0);
}

int		init_server(t_server_info *server, int port)
{
  server->s_in_size = sizeof(server->s_in_client);
  if (init_socket(server, port) == -1)
    return (-1);
  if (bind(server->server_fd, (const struct sockaddr *)&(server->s_in), sizeof(server->s_in)) == -1)
    {
      if (close(server->server_fd) == -1)
	return (-1);
      return (-1);
    }
  listen(server->server_fd, 50); /* valeur 50 à voir */
  return (0);
}
