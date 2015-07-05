/*
** graphic_actions_2.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/graphix
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 08:02:13 2015 Oscar
** Last update Sun Jul  5 15:47:59 2015 Oscar
*/

#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>
#include	<unistd.h>
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
	  sprintf(end, "ppo %d %d %d %d\n",
		  player_fd, player->x,
		  player->y, get_orientation(player));
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
  char		end[56];
  char		dump[56];
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
	  bzero(dump, 56);
	  dump_inventory(player, dump);
	  sprintf(end, "pin %d %d %d%s\n",
		  player_fd, player->x, player->y, dump);
	  write(client->fd, end, strlen(end));
	  return (0);
	}
      player = player->next;
    }
  return (gfx_sbp(data, client, arg));
}

int		gfx_pbc(t_game *data, t_graphix *client,
			int fd, char *msg)
{
  char		end[56];

  (void) data;
  bzero(end, 56);
  sprintf(end, "pbc %d %s\n", fd, msg);
  write(client->fd, end, strlen(end));
  return (0);
}
