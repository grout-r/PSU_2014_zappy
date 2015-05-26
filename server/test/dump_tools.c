/*
** dump_tools.c for TO DELETE in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Wed May 20 14:06:43 2015 Oscar Morizet
** Last update Tue May 26 15:11:20 2015 Oscar Morizet
*/

#include	<stdio.h>
#include	"server.h"

void		dump_map(t_game *game)
{
  t_map_case	***map = game->map;
  int		x;
  int		y = 0;

  while (y != game->map_size_y)
    {
      x = 0;
      while (x != game->map_size_x)
	{
	  printf("X[%d] Y[%d] : ", x, y);
	  while (map[y][x] != NULL)
	    {
	      printf("| val %d", (int) map[y][x]->obj);
	      map[y][x] = map[y][x]->next;
	    }
	  ++x;
	  printf("\n");
	}
      ++y;
    }
}

void		dump_teams(t_game *game)
{
  t_team	*tmp;

  tmp = game->teams;
  while (tmp != NULL)
    {
      printf("Team: %s id: %d players: %d\n",
	     tmp->name, tmp->id, tmp->players_nb);
      tmp = tmp->next;
    }
}
