/*
** action_avance.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:15:14 2015 Oscar Morizet
** Last update Tue Jun 23 08:22:18 2015 Oscar
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		<strings.h>
#include		"server.h"

void			ppo_to_all(t_game *data, t_player *player)
{
  t_graphix		*tmp;
  char			str_fd[56];

  bzero(str_fd, 56);
  tmp = data->cameras;
  sprintf(str_fd, "%d", player->fd);
  while (tmp != NULL)
    {
      gfx_ppo(data, tmp, str_fd);
      tmp = tmp->next;
    }
}

void			globify(t_game *data, int *x, int *y)
{
  if (*x < 0)
    *x = data->map_size_x - 1;
  else if (*x > data->map_size_x - 1)
    *x = 0;
  if (*y < 0)
    *y = data->map_size_y - 1;
  else if (*y > data->map_size_y - 1)
    *y = 0;
}

int			action_avance(t_game *data, t_player *player_data, char *arg)
{
  t_orientation		orient;
  int			new_x;
  int			new_y;

  (void) arg;
  new_x = player_data->x;
  new_y = player_data->y;
  orient = player_data->orientation;
  if (orient == LEFT)
    --new_x;
  else if (orient == UP)
    --new_y;
  else if (orient == RIGHT)
    ++new_x;
  else if (orient == DOWN)
    ++new_y;
  globify(data, &new_x, &new_y);
  if (move_player_to(data, player_data, new_x, new_y) == -1)
    return (-1);
  write(player_data->fd, "ok\n", 3);
  ppo_to_all(data, player_data);
  return (0);
}
