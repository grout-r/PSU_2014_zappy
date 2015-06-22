/*
** teams_2.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 18:51:59 2015 Oscar
** Last update Mon Jun 22 19:02:13 2015 Oscar
*/

#include	<stdlib.h>
#include	"server.h"

char		*get_team_by_id(t_game *data, int id)
{
  t_team	*tmp;

  tmp = data->teams;
  while (tmp != NULL)
    {
      if (tmp->id == id)
	return (tmp->name);
      tmp = tmp->next;
    }
  return (NULL);
}
