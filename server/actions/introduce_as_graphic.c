/*
** introduce_as_graphic.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/actions
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sun Jun 21 12:38:48 2015 Oscar
** Last update Tue Jun 23 14:16:40 2015 Oscar
*/

#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<strings.h>
#include	"server.h"

int		introduce_as_graphical_client(t_game *data, int fd)
{
  t_graphix	*client;
  t_egg		*egg;
  t_player	*tmp;

  if (!(client = add_client_to_cameras(data, fd)))
    return (-1);
  gfx_msz(data, client, NULL);
  gfx_sgt(data, client, NULL);
  gfx_mct(data, client, NULL);
  gfx_tna(data, client, NULL);
  tmp = data->players;
  egg = data->eggs;
  while (tmp != NULL)
    {
      gfx_pnw(data, client, tmp->fd);
      tmp = tmp->next;
    }
  while (egg != NULL)
    {
      gfx_enw(data, client, egg);
      egg = egg->next;
    }
  return (0);
}
