/*
** players.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Sun Jun 21 13:24:42 2015 Oscar
** Last update Tue Jun 23 08:42:05 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<strings.h>
#include	"server.h"

void		pdi_to_all(t_game *data, t_player *player)
{
  t_graphix    	*tmp;

  tmp = data->cameras;
  while (tmp != NULL)
    {
      gfx_pdi(data, tmp, player->fd);
      tmp = tmp->next;
    }
}

int		player_dies(t_game *game, t_player *player)
{
  remove_map_case_element(&(game->map[player->y][player->x]),
			  PLAYER);
  if (remove_client_from_players(game, player->fd) == -1)
    return (-1);
  write(player->fd, "mort\n", 5);
  pdi_to_all(game, player);
  close(player->fd);
  return (0);
}

t_player	*get_player_data(t_game *game_data, int fd)
{
  t_player	*tmp;

  tmp = game_data->players;
  while (tmp != NULL)
    {
      if (tmp->fd == fd)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

t_player	*add_client_to_players(t_game *game, int player_fd)
{
  t_player	*new;
  t_player	*tmp;

  if ((new = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  new->fd = player_fd;
  new->next = NULL;
  if (init_player(game, new) == -1)
    return (NULL);
  if (!game->players)
    game->players = new;
  else
    {
      tmp = game->players;
      while (tmp->next)
        tmp = tmp->next;
      tmp->next = new;
    }
  return (new);
}

int		remove_client_from_players(t_game *game, int player_fd)
{
  t_player	*tofree;
  t_player	*tmp;

  tmp = game->players;
  if (game->players->fd == player_fd)
    {
      game->players = game->players->next;
      return (0);
    }
  while (tmp->next && tmp->next->fd != player_fd)
    tmp = tmp->next;
  if (tmp->next == NULL)
    return (0);
  tofree = tmp->next;
  tmp->next = tofree->next;
  free(tofree);
  close(player_fd);
  return (0);
}
