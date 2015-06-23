/*
** graphic_actions_3.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/graphix
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 08:03:01 2015 Oscar
** Last update Tue Jun 23 12:13:17 2015 Oscar
*/

#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>
#include	<unistd.h>
#include	"server.h"

int		gfx_pic(t_game *data, t_graphix *client, char *arg)
{
  (void) data;
  (void) client;
  (void) arg;
  return (0);
}

int		gfx_pie(t_game *data, t_graphix *client, char *arg)
{
  (void) data;
  (void) client;
  (void) arg;
  return (0);
}

int		gfx_pfk(t_game *data, t_graphix *client, int fd)
{
  char		end[56];

  (void) data;
  bzero(end, 56);
  sprintf(end, "pfk %d\n", fd);
  write(client->fd, end, strlen(end));
  return (0);
}

int		gfx_pdr(t_game *data, t_graphix *client, char *arg)
{
  (void) data;
  (void) client;
  (void) arg;
  return (0);
}

int		gfx_pgt(t_game *data, t_graphix *client, char *arg)
{
  (void) data;
  (void) client;
  (void) arg;
  return (0);
}
