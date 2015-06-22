/*
** graphic_actions_5.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/graphix
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 08:04:48 2015 Oscar
** Last update Mon Jun 22 19:34:07 2015 Oscar
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	"server.h"

int		gfx_sgt(t_game *data, t_graphix *client, char *arg)
{
  char		res[56];

  (void) arg;
  bzero(res, 56);
  sprintf(res, "sgt %d\n", (int) data->action_delay);
  write(client->fd, res, strlen(res));
  return (0);
}

int		gfx_seg(t_game *data, t_graphix *client, char *arg)
{
  (void) data;
  (void) client;
  (void) arg;
  return (0);
}

int		gfx_smg(t_game *data, t_graphix *client, char *arg)
{
  (void) data;
  (void) client;
  (void) arg;
  return (0);
}

int		gfx_suc(t_game *data, t_graphix *client, char *arg)
{
  char		err[20];

  (void) arg;
  (void) data;
  bzero(err, sizeof(char) * 20);
  sprintf(err, "suc\n");
  write(client->fd, err, strlen(err));
  return (0);
}

int		gfx_sbp(t_game *data, t_graphix *client, char *arg)
{
  char		err[20];

  (void) arg;
  (void) data;
  bzero(err, sizeof(char) * 20);
  sprintf(err, "sbp\n");
  write(client->fd, err, strlen(err));
  return (0);
}
