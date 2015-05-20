/*
** dump_tools.c for TO DELETE in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Wed May 20 14:06:43 2015 Oscar Morizet
** Last update Wed May 20 14:20:58 2015 Oscar Morizet
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
	      printf("| val %d", map[y][x]->val);
	      map[y][x] = map[y][x]->next;
	    }
	  ++x;
	  printf("\n");
	}
      ++y;
    }
}
