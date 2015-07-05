/*
** graphic_actions_3.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/graphix
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 08:03:01 2015 Oscar
** Last update Sun Jul  5 16:20:42 2015 Oscar
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

void		bct_to_all(t_game *data, t_player *player)
{
  t_graphix	*tmp;
  char		pos[56];

  bzero(pos, 56);
  tmp = data->cameras;
  sprintf(pos, "%d %d", player->x, player->y);
  while (tmp != NULL)
    {
      gfx_bct(data, tmp, pos);
      tmp = tmp->next;
    }
}

void		pin_to_all(t_game *data, t_player *player)
{
  t_graphix	*tmp;
  char		str_fd[56];

  bzero(str_fd, 56);
  tmp = data->cameras;
  sprintf(str_fd, "%d", player->fd);
  while (tmp != NULL)
    {
      gfx_pin(data, tmp, str_fd);
      tmp = tmp->next;
    }
}
