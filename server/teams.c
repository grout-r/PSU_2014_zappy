/*
** teams.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Wed May 20 15:35:10 2015 Oscar Morizet
** Last update Fri May 22 19:08:34 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	<string.h>
#include	"server.h"

int		create_team(t_game *game, char *team_name)
{
  static int	next_id = 1;
  t_team	*new_team;
  t_team	*tmp;

  if ((new_team = malloc(sizeof(t_team))) == NULL)
    return (-1);
  strcpy(new_team->name, team_name);
  new_team->id = next_id;
  new_team->players_nb = 0;
  new_team->next = NULL;
  if (game->teams == NULL)
    game->teams = new_team;
  else
    {
      tmp = game->teams;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_team;
    }
  ++next_id;
  return (0);
}

void		team_free_slot(t_game *game, int team_id)
{
  t_team	*tmp;

  if (game->teams == NULL)
    return ;
  tmp = game->teams;
  while (tmp != NULL)
    {
      if (tmp->id == team_id)
	{
	  tmp->players_nb = tmp->players_nb - 1;
	  return ;
	}
      tmp = tmp->next;
    }
}

void		team_add_slot(t_game *game, int team_id)
{
  t_team	*tmp;

  if (game->teams == NULL)
    return ;
  tmp = game->teams;
  while (tmp != NULL)
    {
      if (tmp->id == team_id)
	{
	  tmp->players_nb = tmp->players_nb + 1;
	  return ;
	}
      tmp = tmp->next;
    }
}
