/*
** graphical_clients.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 07:17:01 2015 Oscar
** Last update Mon Jun 22 07:20:04 2015 Oscar
*/

#include	<stdlib.h>
#include	"server.h"

t_graphix	*get_camera_data(t_game *game_data, int fd)
{
  t_graphix	*tmp;

  tmp = game_data->cameras;
  while (tmp != NULL)
    {
      if (tmp->fd == fd)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

t_graphix	*add_client_to_cameras(t_game *game, int fd)
{
  t_graphix	*new;
  t_graphix	*tmp;

  if ((new = malloc(sizeof(t_graphix))) == NULL)
    return (NULL);
  new->fd = fd;
  new->next = NULL;
  if (!game->cameras)
    game->cameras = new;
  else
    {
      tmp = game->cameras;
      while (tmp->next)
        tmp = tmp->next;
      tmp->next = new;
    }
  return (new);
}

int		remove_client_from_cameras(t_game *game, int fd)
{
  t_graphix	*tofree;
  t_graphix	*tmp;

  tmp = game->cameras;
  if (game->cameras->fd == fd)
    {
      game->cameras = game->cameras->next;
      return (0);
    }
  while (tmp->next && tmp->next->fd != fd)
    tmp = tmp->next;
  if (tmp->next == NULL)
    return (0);
  tofree = tmp->next;
  tmp->next = tofree->next;
  free(tofree);
  return (0);
}
