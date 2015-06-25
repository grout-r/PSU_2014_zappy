/*
** standby_clients.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/core
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sun Jun 21 13:02:08 2015 Oscar
** Last update Sun Jun 21 14:10:21 2015 Oscar
*/

#include		<sys/select.h>
#include		<sys/types.h>
#include		<stdlib.h>
#include		<strings.h>
#include		<unistd.h>
#include		"server.h"

int			add_new_standby_client(t_game *game,
					       int client_fd)
{
  t_standby_client	*new;
  t_standby_client     	*tmp;

  if ((new = malloc(sizeof(t_standby_client))) == NULL)
    return (-1);
  new->fd = client_fd;
  new->next = NULL;
  if (!game->standby_clients)
    game->standby_clients = new;
  else
    {
      tmp = game->standby_clients;
      while (tmp->next)
        tmp = tmp->next;
      tmp->next = new;
    }
  return (0);
}

int			remove_standby_client(t_game *game,
					      int client_fd)
{
  t_standby_client	*tofree;
  t_standby_client	*tmp;
  
  tmp = game->standby_clients;
  if (game->standby_clients->fd == client_fd)
    {
      game->standby_clients = game->standby_clients->next;
      return (0);
    }
  while (tmp->next && tmp->next->fd != client_fd)
    tmp = tmp->next;
  if (tmp->next == NULL)
    return (0);
  tofree = tmp->next;
  tmp->next = tofree->next;
  free(tofree);
  return (0);
}

int			accept_new_client(t_server_info *server, t_game *game_data)
{
  int			client_fd;
  struct sockaddr_in	client_sin;
  socklen_t		client_sin_len;

  client_sin_len = sizeof(struct sockaddr *);
  if ((client_fd = accept(server->server_fd,
                              (struct sockaddr *)&client_sin,
                              &client_sin_len)) == -1)
    return (-1);
  if (add_new_standby_client(game_data, client_fd) == -1)
    return (-1);
  printf("Added to standby\n");
  return (0);
}
