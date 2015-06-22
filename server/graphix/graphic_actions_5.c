/*
** graphic_actions_5.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/graphix
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 08:04:48 2015 Oscar
** Last update Mon Jun 22 11:21:06 2015 Oscar
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"server.h"

int		gfx_seg(t_game *data, t_graphix *client, char *arg)
{
}

int		gfx_smg(t_game *data, t_graphix *client, char *arg)
{
}

int		gfx_suc(t_game *data, t_graphix *client, char *arg)
{
  char		err[20];

  bzero(err, sizeof(char) * 20);
  sprintf(err, "Commande inconnue\n");
  write(client->fd, err, strlen(err));
}

int		gfx_sbp(t_game *data, t_graphix *client, char *arg)
{
  char		err[20];

  bzero(err, sizeof(char) * 20);
  sprintf(err, "Mauvais parametres\n");
  write(client->fd, err, strlen(err));
}
