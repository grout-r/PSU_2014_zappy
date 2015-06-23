/*
** egg.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/components
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Tue Jun 23 11:30:05 2015 Oscar
** Last update Tue Jun 23 15:27:50 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<strings.h>
#include	"server.h"

void		eht_to_all(t_game *data, int egg_id)
{
  t_graphix    	*tmp;

  tmp = data->cameras;
  while (tmp != NULL)
    {
      gfx_eht(data, tmp, egg_id);
      tmp = tmp->next;
    }
}

void		ebo_to_all(t_game *data, int egg_id)
{
  t_graphix    	*tmp;

  tmp = data->cameras;
  while (tmp != NULL)
    {
      gfx_ebo(data, tmp, egg_id);
      tmp = tmp->next;
    }
}

int		egg_process_cycle(t_game *game, t_egg *egg)
{
  t_team	*tmp;

  tmp = game->teams;
  --egg->eclosion;
  if (egg->eclosion == 0)
    {
      eht_to_all(game, egg->id);
      while (tmp != NULL)
	{
	  if (tmp->id == egg->team_id)
	    ++tmp->extra_place;
	  tmp = tmp->next;
	}
    }
  return (0);
}

t_egg		*add_egg(t_game *game, t_player *player)
{
  t_egg		*new;
  t_egg		*tmp;
  static int	egg_id = 1;

  if ((new = malloc(sizeof(t_egg))) == NULL)
    return (NULL);
  new->team_id = player->team_id;
  new->owner = player->fd;
  new->id = egg_id;
  new->x = player->x;
  new->y = player->y;
  new->next = NULL;
  new->eclosion = BASE_ECLOSION_TIME;
  if (!game->eggs)
    game->eggs = new;
  else
    {
      tmp = game->eggs;
      while (tmp->next)
        tmp = tmp->next;
      tmp->next = new;
    }
  ++egg_id;
  return (new);
}

void		use_egg(t_game *game, int team_id)
{
  t_egg		*tofree;
  t_egg		*tmp;

  tmp = game->eggs;
  if (game->eggs->team_id == team_id)
    {
      ebo_to_all(game, game->eggs->id);
      game->eggs = game->eggs->next;
      return ;
    }
  while (tmp->next && tmp->next->team_id != team_id)
    tmp = tmp->next;
  if (tmp->next == NULL)
    return ;
  tofree = tmp->next;
  ebo_to_all(game, tofree->id);
  tmp->next = tofree->next;
  free(tofree);
}
