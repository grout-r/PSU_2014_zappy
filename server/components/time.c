/*
1;2802;0c1;2802;0c1;2802;0c1;2802;0c1;2802;0c** time.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/components
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Fri Jun  5 00:24:48 2015 Oscar
** Last update Fri Jun  5 17:37:12 2015 Oscar
*/

#include		<stdlib.h>
#include		<sys/time.h>
#include		<string.h>
#include		<strings.h>
#include		"server.h"
#include		"timer.h"

void			update_timer(t_game *game, t_server_info *server, struct timeval *timeset)
{
  struct timeval	timediff;

  timersub(&timeset[END_TIMER], &timeset[START_TIMER], &timediff);
  printf("Exec Time : %ld\n", timediff.tv_usec);
  timersub(server->base_cycle_time, &timediff, server->cycle_end);
  server->cycle_end->tv_sec = 0;
  printf("Next Durée : %d\n", server->cycle_end->tv_usec);
}

int			init_timer(t_game *game, t_server_info *server)
{
  float			tmp;

  if ((server->cycle_end = malloc(sizeof(struct timeval))) == NULL)
    return (-1);
  if ((server->base_cycle_time = malloc(sizeof(struct timeval))) == NULL)
    return (-1);
  tmp = 1.0 / game->action_delay;
  server->base_cycle_time->tv_sec = 0;
  server->base_cycle_time->tv_usec = tmp * USEC_TO_SEC_CONV;
  memcpy(server->cycle_end, server->base_cycle_time, sizeof(struct timeval));
  return (0);
}
