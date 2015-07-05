/*
** graphic_actions_3.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/graphix
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 08:03:01 2015 Oscar
** Last update Sun Jul  5 15:17:02 2015 Oscar
*/

#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>
#include	<unistd.h>
#include	"server.h"

int		gfx_pfk(t_game *data, t_graphix *client, int fd)
{
  char		end[56];

  (void) data;
  bzero(end, 56);
  sprintf(end, "pfk %d\n", fd);
  write(client->fd, end, strlen(end));
  return (0);
}

int		gfx_pdr(t_game *data, t_graphix *client,
			int fd, int res)
{
  char		end[56];

  (void) data;
  bzero(end, 56);
  sprintf(end, "pdr %d %d\n", fd, res);
  write(client->fd, end, strlen(end));
  return (0);
}

int		gfx_pgt(t_game *data, t_graphix *client,
			int fd, int res)
{
  char		end[56];

  (void) data;
  bzero(end, 56);
  sprintf(end, "pgt %d %d\n", fd, res);
  write(client->fd, end, strlen(end));
  return (0);
}
