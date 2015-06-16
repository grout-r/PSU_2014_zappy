/*
** dump_case.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/components
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun  1 13:26:03 2015 Oscar Morizet
** Last update Mon Jun  1 15:15:59 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	<string.h>
#include	"server.h"

char		*dump_case(t_map_case *mcase, int index)
{
  int		add_size;
  char		*dump;
  char		*convert[] = {"joueur", "nourriture", "linemate", "deraumere",
			      "sibur", "mendiane", "phiras", "thystame", NULL};

  if ((dump = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  dump[0] = 0;
  while (mcase != NULL)
    {
      add_size = sizeof(char) * strlen(convert[mcase->obj]) + 2;
      dump = realloc(dump, (sizeof(char) * strlen(dump)) + add_size);
      if (!dump)
	return (NULL);
      if (index != 0)
	strcat(dump, " ");
      strcat(dump, convert[mcase->obj]);
      mcase = mcase->next;
      ++index;
    }
  return (dump);
}
