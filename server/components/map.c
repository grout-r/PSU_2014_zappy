/*
** map.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 18 17:15:46 2015 Oscar Morizet
** Last update Mon Jun 22 19:19:45 2015 Oscar
*/

#include	<stdlib.h>
#include	"server.h"
#include	"map.h"

void		remove_map_case_element(t_map_case **list, t_object obj)
{
  t_map_case	*tofree;
  t_map_case	*tmp;

  tmp = *list;
  if (tmp->obj == obj)
    {
      *list = (*list)->next;
      free(tmp);
      return ;
    }
  while (tmp->next && tmp->next->obj != obj)
    tmp = tmp->next;
  if (tmp->next == NULL)
    return ;
  tofree = tmp->next;
  tmp->next = tofree->next;
  free(tofree);
}

int		add_map_case_element(t_map_case **list, t_object obj)
{
  t_map_case	*new;
  t_map_case	*tmp;

  tmp = *list;
  if ((new = malloc(sizeof(t_map_case))) == NULL)
    return (-1);
  new->obj = obj;
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

int		check_object_presence_in_map_case(t_map_case *list,
						  t_object object)
{
  while (list->next != NULL)
    {
      if (list->obj == object)
	return (1);
      list = list->next;
    }
  return (0);
}

int		move_player_to(t_game *game, t_player *player,
			       int new_x, int new_y)
{
  
  remove_map_case_element(&(game->map[player->y][player->x]),
			  PLAYER);
  if (add_map_case_element(&(game->map[new_y][new_x]),
			   PLAYER) == -1)
    return (-1);
  player->x = new_x;
  player->y = new_y;
  return (0);
}
