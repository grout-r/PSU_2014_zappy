/*
** graphic_actions_1.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/graphix
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 08:00:18 2015 Oscar
** Last update Sun Jul  5 15:12:50 2015 Oscar
*/

#include	<stdlib.h>
#include	<strings.h>
#include	<string.h>
#include	<unistd.h>
#include	"server.h"

int		gfx_msz(t_game *data,
			t_graphix *client, char *arg)
{
  char		res[56];

  (void) arg;
  bzero(res, 56);
  sprintf(res, "msz %d %d\n", data->map_size_x,
	  data->map_size_y);
  write(client->fd, res, strlen(res));
  return (0);
}

int		gfx_bct(t_game *data,
			t_graphix *client, char *arg)
{
  int		x;
  int		y;
  char		res[56];
  char		end[56];

  bzero(res, 56);
  bzero(end, 56);
  if (get_bct_coords(data, arg, &x, &y) == -1)
    {
      gfx_sbp(data, client, arg);
      return (1);
    }
  dump_case_for_gfx(data, res, x, y);
  sprintf(end, "bct %d %d%s\n", x, y, res);
  write(client->fd, end, strlen(end));
  return (0);
}

int		gfx_mct(t_game *data,
			t_graphix *client, char *arg)
{
  int		x;
  int		y;
  char		res[56];
  char		end[56];

  y = 0;
  (void) arg;
  while (y != data->map_size_y)
    {
      x = 0;
      while (x != data->map_size_x)
	{
	  bzero(end, 56);
	  bzero(res, 56);
	  dump_case_for_gfx(data, res, x, y);
	  sprintf(end, "bct %d %d%s\n", x, y, res);
	  write(client->fd, end, strlen(end));
	  ++x;
	}
      ++y;
    }
  return (0);
}

int		gfx_tna(t_game *data,
			t_graphix *client, char *arg)
{
  char		end[56];
  t_team	*tmp;

  (void) arg;
  tmp = data->teams;
  while (tmp != NULL)
    {
      bzero(end, 56);
      sprintf(end, "tna %s\n", tmp->name);
      write(client->fd, end, strlen(end));
      tmp = tmp->next;
    }
  return (0);
}

int		gfx_pnw(t_game *data,
			t_graphix *client, int fd)
{
  char		end[56];
  t_player	*player;

  player = data->players;
  while (player != NULL)
    {
      if (player->fd == fd)
	{
	  bzero(end, 56);
	  sprintf(end, "pnw %d %d %d %d %d %s\n",
		  fd, player->x, player->y,
		  get_orientation(player), player->level,
		  get_team_by_id(data, player->team_id));
	  write(client->fd, end, strlen(end));
	  return (0);
	}
      player = player->next;
    }
  return (gfx_sbp(data, client, NULL));
}
