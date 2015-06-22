/*
1;2802;0c** graphic_actions_2.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/graphix
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 08:02:13 2015 Oscar
** Last update Mon Jun 22 18:25:19 2015 Oscar
*/

#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>
#include	"server.h"

int		gfx_ppo(t_game *data,
			t_graphix *client, char *arg)
{
  char		end[56];
  int		player_fd;
  t_player	*player;

  if (!check_if_num(arg) || *arg == 0)
    return (gfx_sbp(data, client, arg));
  player_fd = atoi(arg);
  player = data->players;
  while (player != NULL)
    {
      if (player->fd == player_fd)
	{
	  bzero(end, 56);
	  sprintf(end, "ppo %d %d %d\n",
		  player_fd, player->x, player->y);
	  write(client->fd, end, strlen(end));
	  return (0);
	}
      player = player->next;
    }
  return (gfx_sbp(data, client, arg));
}

int		gfx_plv(t_game *data, t_graphix *client, char *arg)
{
  char		end[56];
  int		player_fd;
  t_player	*player;

  if (!check_if_num(arg) || *arg == 0)
    return (gfx_sbp(data, client, arg));
  player_fd = atoi(arg);
  player = data->players;
  while (player != NULL)
    {
      if (player->fd == player_fd)
	{
	  bzero(end, 56);
	  sprintf(end, "plv %d %d\n",
		  player_fd, player->level);
	  write(client->fd, end, strlen(end));
	  return (0);
	}
      player = player->next;
    }
  return (gfx_sbp(data, client, arg));
}

int		gfx_pin(t_game *data, t_graphix *client, char *arg)
{
}

int		gfx_pex(t_game *data, t_graphix *client, char *arg)
{
}

int		gfx_pbc(t_game *data, t_graphix *client, char *arg)
{
}

int		gfx_pic(t_game *data, t_graphix *client, char *arg)
{
}
