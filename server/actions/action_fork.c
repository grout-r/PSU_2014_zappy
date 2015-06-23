/*
** action_fork.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:22:08 2015 Oscar Morizet
** Last update Tue Jun 23 12:11:53 2015 Oscar
*/

#include		<stdlib.h>
#include		<strings.h>
#include		"server.h"

void			pfk_to_all(t_game *data, t_player *player)
{
  t_graphix		*tmp;
  char			str_fd[56];

  bzero(str_fd, 56);
  tmp = data->cameras;
  while (tmp != NULL)
    {
      gfx_pfk(data, tmp, player->fd);
      tmp = tmp->next;
    }
}

int			action_fork(t_game *data, t_player *player_data, char *arg)
{
  (void) arg;
  if (add_egg(data, player_data) == NULL)
    return (-1);
  pfk_to_all(data, player_data);
  return (0);
}
