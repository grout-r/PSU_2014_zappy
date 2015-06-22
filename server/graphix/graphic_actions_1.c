/*
** graphic_actions_1.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/graphix
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 08:00:18 2015 Oscar
** Last update Mon Jun 22 11:20:12 2015 Oscar
*/

#include	<stdlib.h>
#include	<strings.h>
#include	<string.h>
#include	"server.h"

int		gfx_msz(t_game *data, t_graphix *client, char *arg)
{
  char		res[56];

  bzero(res, 56);
  sprintf(res, "msz %d %d\n", data->map_size_x, data->map_size_y);
  write(client->fd, res, strlen(res));
  return (0);
}

int		gfx_bct(t_game *data, t_graphix *client, char *arg)
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
  sprintf(end, "bct%s\n", res);
  write(client->fd, end, strlen(end));
  return (0);
}

int		gfx_tna(t_game *data, t_graphix *client, char *arg)
{
}

int		gfx_pnw(t_game *data, t_graphix *client, char *arg)
{
}

int		gfx_ppo(t_game *data, t_graphix *client, char *arg)
{
}
