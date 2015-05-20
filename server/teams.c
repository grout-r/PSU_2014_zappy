/*
** teams.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Wed May 20 15:35:10 2015 Oscar Morizet
** Last update Wed May 20 15:42:44 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"

int		create_team(t_game *game, char *team_name)
{
  static int	next_id = 1;

  printf("Created team %d %s\n", next_id, team_name);
  ++next_id;
}


void		team_free_slot(int team_id)
{
}

void		team_add_slot(int team_id)
{
}
