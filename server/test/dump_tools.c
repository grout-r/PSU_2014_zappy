/*
** dump_tools.c for TO DELETE in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Wed May 20 14:06:43 2015 Oscar Morizet
** Last update Fri Jun 19 19:48:05 2015 Oscar
*/

#include	<stdio.h>
#include	"server.h"

void		dump_map(t_game *game)
{
  t_map_case	***map = game->map;
  int		i = 0;
  int		x = 0;
  int		y = 0;

  printf("-----------------------\n");
  while (y != game->map_size_y)
    {
      x = 0;
      while (x != game->map_size_x)
	{
	  printf("X[%d] Y[%d] : %s\n", x, y, dump_case(game, map[y][x], 0));
	  ++x;
	}
      ++y;
    }
  printf("-----------------------\n");
}

void		print_map(t_game *game)
{
  t_map_case	***map = game->map;
  t_map_case	*tmp;
  int		i = 0;
  int		x = 0;
  int		y = 0;

  
  printf(" -");
  while (i != game->map_size_x * 2)
    {
      printf("-");
      i++;
    }
  printf("\n");
  while (y != game->map_size_y)
    {
      x = 0;
      printf(" ");
      while (x != game->map_size_x)
	{
	  tmp = map[y][x];
	  printf("|");
	  while (tmp != NULL)
	    {
	      if (tmp->obj == PLAYER)
		{
		  printf("X");
		  break;
		} 
	      tmp = tmp->next;
	    }
	  if (tmp == NULL)
	    printf(" ");
	  ++x;
	}
      printf("|\n");
      ++y;
    }
  printf(" -");
  i = 0;
  while (i != game->map_size_x * 2)
    {
      printf("-");
      i++;
    }
  printf("\n");
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
