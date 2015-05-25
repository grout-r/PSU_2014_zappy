/*
** manage_client.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May  4 16:20:47 2015 Oscar Morizet
** Last update Mon May 25 15:41:11 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"

int		add_client_to_players(t_game *game, int player_fd)
{
  t_player	*new;
  t_player	*tmp;

  if ((new = malloc(sizeof(t_player))) == NULL)
    return (-1);
  new->fd = player_fd;
  new->next = NULL;
  if (init_player(game, new) == -1)
    return (-1);
  if (!game->players)
    game->players = new;
  else
    {
      tmp = game->players;
      while (tmp->next)
        tmp = tmp->next;
      tmp->next = new;
    }
  if (add_map_case_element(&(game->map[new->y][new->x]), new->fd) == -1)
  move_player_to(game, new, new->x, new->y);
  return (0);
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
  return (0);
}
