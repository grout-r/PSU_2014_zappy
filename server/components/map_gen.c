/*
** map_gen.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/components
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue May 26 14:53:56 2015 Oscar Morizet
** Last update Tue May 26 15:21:59 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	"server.h"
#include	"object.h"

t_object	get_random_item()
{
  int		int_object;

  int_object = (rand() % (MAX_OBJECTS - 1)) + 1;
  return ((t_object) int_object);
}

int		spawn_on_case()
{
  int		value;

  value = (rand() % 3) + 1;
  if (value == 1)
    return (1);
  return (0);
}

void		map_spawn_items(t_game *game)
{
  int		i;
  int		x;
  int		y;

  y = 0;
  while (y != game->map_size_y)
    {
      x = 0;
      while (x != game->map_size_x)
	{
	  if (spawn_on_case())
	    {
	      i = (rand() % 5);
	      while (i != 5)
		{
		  add_map_case_element(&(game->map[y][x]),
				       get_random_item());
		  ++i;
		}
	    }
	  ++x;
	}
      ++y;
    }
}
