/*
** dump_case.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/components
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun  1 13:26:03 2015 Oscar Morizet
** Last update Mon Jun 22 17:46:33 2015 Oscar
*/

#include	<stdlib.h>
#include	<string.h>
#include	"server.h"

int		do_alloc(char **dump, char *object)
{
  int		add_size;
  
  add_size = sizeof(char) * strlen(object) + 2;
  *dump = realloc(*dump, (sizeof(char) * strlen(*dump)) + add_size);
  if (*dump == NULL)
    return (-1);
  return (0);
}

char		*dump_case(t_game *data, t_map_case *mcase, int index)
{
  int		skip_myself;
  char		*dump;

  if ((dump = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  dump[0] = 0;
  skip_myself = 0;
  while (mcase != NULL)
    {
      if ((mcase->obj == PLAYER && !skip_myself) && index == 0)
	skip_myself = 1;
      else
	{
	  if (do_alloc(&dump, data->inventory_names[mcase->obj]) == -1)
	    return (NULL);
	  if (index != 0)
	    strcat(dump, " ");
	  strcat(dump, data->inventory_names[mcase->obj]);
	}
      mcase = mcase->next;
      ++index;
    }
  return (dump);
}

void		dump_case_for_gfx(t_game *game_data, char *str, int x, int y)
{
  t_map_case	*map_case;
  t_object	item;
  int		item_count;
  char		char_item_count[5];
  
  item = NOURRITURE;
  while (item != NONE)
    {
      bzero(char_item_count, 5);
      item_count = 0;
      map_case = game_data->map[y][x];
      while (map_case != NULL)
	{
	  if (map_case->obj == item)
	    ++item_count;
	  map_case = map_case->next;
	}
      sprintf(char_item_count, " %d", item_count);
      strcat(str, char_item_count);
      ++item;
    }
}
