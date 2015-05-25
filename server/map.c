/*
** map.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 18 17:15:46 2015 Oscar Morizet
** Last update Mon May 25 15:41:22 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"
#include	"map.h"

int		init_map_case(t_map_case ***map, int x, int y)
{
  t_map_case	*new_case;

  if ((new_case = malloc(sizeof(t_map_case))) == NULL)
    return (-1);
  new_case->val = 5555;
  new_case->next = NULL;
  map[y][x] = new_case;
  return (0);
}

int		init_map(t_game *game)
{
  int		x;
  int		y;
  size_t	xsize;

  y = 0;
  if ((game->map = malloc(sizeof(t_map_case *) * game->map_size_y)) == NULL)
    return (-1);
  xsize = sizeof(t_map_case) * game->map_size_x;
  while (y != game->map_size_y)
    {
      x = 0;
      if ((game->map[y] = malloc(xsize)) == NULL)
	return (-1);
      while (x != game->map_size_x)
	{
	  game->map[y][x] = NULL;
	  ++x;
	}
      ++y;
    }
  return (0);
}

void		remove_map_case_element(t_map_case **list, int val)
{
  t_map_case	*tofree;
  t_map_case	*tmp;

  tmp = *list;
  if (tmp->val == val)
    {
      *list = (*list)->next;
      free(tmp);
      return ;
    }
  while (tmp->next && tmp->next->val != val)
    tmp = tmp->next;
  if (tmp->next == NULL)
    return ;
  tofree = tmp->next;
  tmp->next = tofree->next;
  free(tofree);
}

int		add_map_case_element(t_map_case **list, int val)
{
  t_map_case	*new;
  t_map_case	*tmp;

  tmp = *list;
  if ((new = malloc(sizeof(t_map_case))) == NULL)
    return (-1);
  new->val = val;
  new->next = NULL;
  if (*list == NULL)
    *list = new;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (0);
}

int		move_player_to(t_game *game, t_player *player, int new_x, int new_y)
{
  remove_map_case_element(&(game->map[player->y][player->x]),
			  player->fd);
  if (add_map_case_element(&(game->map[new_y][new_x]),
			   player->fd) == -1)
    return (-1);
  return (0);
}
