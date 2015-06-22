/*
** introduce.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 25 16:10:14 2015 Oscar Morizet
** Last update Mon Jun 22 19:10:47 2015 Oscar
*/

#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<strings.h>
#include	"server.h"

int		introduce(t_game *data, char *message, int client_fd)
{
  if (strcmp(message, GRAPHIX_INTRODUCTION) == 0)
    {
      if (introduce_as_graphical_client(data, client_fd) == -1)
	return (-1);
    }
  else
    {
      if (introduce_as_player(data, message, client_fd) == -1)
	return (-1);
    }
  remove_standby_client(data, client_fd);
  return (0);
}
