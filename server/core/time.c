/*
** time.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Fri Jun 12 19:55:54 2015 Oscar
** Last update Sun Jun 21 07:42:34 2015 Oscar
*/

#include		<stdlib.h>
#include		<sys/time.h>
#include		<string.h>
#include		<strings.h>
#include		"server.h"
#include		"timer.h"

int			count_extra_cycles(t_server_info *server, struct timeval *timelapse)
{
  int			cycles;
  
  cycles = 0;
  while (timercmp(timelapse, server->base_cycle_time, >))
    {
      timersub(timelapse, server->base_cycle_time, timelapse);
      ++cycles;
    }
  return (cycles);
}

int			update_timer(t_server_info *server,
				     struct timeval *cycle_start,
				     struct timeval *cycle_finish)
{
  struct timeval	timelapse;
  int			cycles;

  cycles = 1;
  timersub(cycle_finish, cycle_start, &timelapse);
  cycles += count_extra_cycles(server, &timelapse);
  timersub(server->base_cycle_time, &timelapse, server->cycle_end);
  return (cycles);
}

int			init_timer(t_game *game, t_server_info *server)
{
  float			tmp;

  if ((server->cycle_end = malloc(sizeof(struct timeval))) == NULL)
    return (-1);
  if ((server->base_cycle_time = malloc(sizeof(struct timeval))) == NULL)
    return (-1);
  server->cycle_end->tv_sec = 0;
  server->cycle_end->tv_usec = 0;  
  server->base_cycle_time->tv_sec = 0;
  server->base_cycle_time->tv_usec = 0;  
  tmp = (1.0 / game->action_delay) * USEC_TO_SEC_CONV;
  if (tmp == 1000000)
    server->base_cycle_time->tv_sec = 1;
  else
    server->base_cycle_time->tv_usec = tmp;
  return (0);
}
