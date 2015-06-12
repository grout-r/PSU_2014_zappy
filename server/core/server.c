/*
1;2802;0c1;2802;0c** server.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Fri Jun  5 17:39:08 2015 Oscar
** Last update Fri Jun 12 23:05:03 2015 Oscar
*/

#include		<sys/select.h>
#include		<sys/time.h>
#include		<stdio.h>
#include		<unistd.h>
#include		"server.h"
#include		"timer.h"

int			make_cycle(t_game *game, t_server_info *server)
{
  t_player		*tmp;

  tmp = game->players;
  if (tmp == NULL)
    return (0);
  while (tmp != NULL)
    {
      if (player_process_cycle(game, tmp) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}

int			cyclify(int cycle_nb, t_game *game, t_server_info *server)
{
  int			i;

  i = 0;
  while (i != cycle_nb)
    {
      if (make_cycle(game, server) == -1)
	return (-1);
      ++i;
    }
  return (0);
}

int		        run(t_game *game_data, t_server_info *server)
{
  struct timeval	cycle_start;
  struct timeval	cycle_finish;
  struct timeval	cycle_start_tmp;
  struct timeval	timelapse;

  gettimeofday(&cycle_start, NULL);
  cycle_start_tmp = cycle_start;
  while (42)
    {
      gettimeofday(&cycle_finish, NULL);
      update_timer(game_data, server, &cycle_start, &cycle_finish);
      reset_sets(server, game_data);
      if (select(server->fd_max + 1,
		 server->fd_reads, NULL, NULL, server->cycle_end) == -1)
	{
	  perror("Select error: ");
	  return (-1);
	}
      gettimeofday(&cycle_start, NULL);
      timersub(&cycle_start, &cycle_start_tmp, &timelapse);
      //printf("TIMELAPSE %ld s / %ld microseconds\n", timelapse.tv_sec, timelapse.tv_usec);
      cycle_start_tmp = cycle_start;
      if (server->cycle_end->tv_usec == 0 && server->cycle_end->tv_sec == 0)
	{
	  if (cyclify(1, game_data, server) == -1)
	    return (-1);
	}
      else
	{
	  if (handle_server_interactions(server, game_data) == -1)
	    return (-1);
	}
    }
  return (0);
}
