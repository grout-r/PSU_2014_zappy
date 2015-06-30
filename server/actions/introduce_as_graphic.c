/*
** introduce_as_graphic.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/actions
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sun Jun 21 12:38:48 2015 Oscar
** Last update Mon Jun 22 07:32:09 2015 Oscar
*/

#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<strings.h>
#include	"server.h"

int		introduce_as_graphical_client(t_game *data, int fd)
{
  t_graphix	*client;

  if (!add_client_to_cameras(data, fd))
    return (-1);
  return (0);
}
