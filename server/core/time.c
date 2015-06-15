/*
1;2802;0c1;2802;0c1;2802;0c1;2802;0c1;2802;0c1;2802;0c1;2802;0c1;2802;0c1;2802;0c** time.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/components
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Fri Jun  5 00:24:48 2015 Oscar
** Last update Sat Jun  6 11:01:10 2015 Oscar
*/

#include		<stdlib.h>
#include		<sys/time.h>
#include		<string.h>
#include		<strings.h>
#include		"server.h"
#include		"timer.h"

void			update_timer(t_game *game, t_server_info *server,
				     struct timeval *cycle_start,
				     struct timeval *cycle_finish)
{
  struct timeval	timelapse;
  
  timersub(cycle_finish, cycle_start, &timelapse);
  printf("exec timelapse +%ld.%ld\n", timelapse.tv_sec, timelapse.tv_usec);
  timersub(server->base_cycle_time, &timelapse, server->cycle_end); 
  server->cycle_end->tv_sec = 0;
}

int			init_timer(t_game *game, t_server_info *server)
{
  float			tmp;

  if ((server->cycle_end = malloc(sizeof(struct timeval))) == NULL)
    return (-1);
  if ((server->base_cycle_time = malloc(sizeof(struct timeval))) == NULL)
    return (-1);
  server->base_cycle_time->tv_sec = 0;
  server->base_cycle_time->tv_usec = 0;  
  tmp = (1.0 / game->action_delay) * USEC_TO_SEC_CONV;
  if (tmp == 1000000)
    server->base_cycle_time->tv_sec = 1;
  else
    server->base_cycle_time->tv_usec = tmp;
  memcpy(server->cycle_end, server->base_cycle_time, sizeof(struct timeval));
  return (0);
}
