/*
** server.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Fri Jun  5 17:39:08 2015 Oscar
** Last update Tue Jun 23 15:28:11 2015 Oscar
*/

#include		<sys/select.h>
#include		<sys/time.h>
#include		<stdio.h>
#include		<unistd.h>
#include		"server.h"
#include		"timer.h"

int			make_cycle(t_game *game)
{
  t_player		*player;
  t_egg			*egg;

  player = game->players;
  egg = game->eggs;
  while (player != NULL)
    {
      if (player_process_cycle(game, player) == -1)
	return (-1);
      player = player->next;
    }
  while (egg != NULL)
    {
      if (egg_process_cycle(game, egg) == -1)
	return (-1);
      egg = egg->next;
    }
  return (0);
}

int			cyclify(int cycle_nb, t_game *game)
{
  int			i;

  i = 0;
  while (i != cycle_nb)
    {
      if (make_cycle(game) == -1)
	return (-1);
      ++i;
    }
  return (0);
}

int			process(t_game *game_data, t_server_info *server, int cycles)
{
  if (server->cycle_end->tv_usec == 0 && server->cycle_end->tv_sec == 0)
    {
      if (cyclify(cycles, game_data) == -1)
	return (-1);
    }
  else
    {
      usleep(server->cycle_end->tv_usec);
      if (handle_server_requests(server, game_data) == -1)
	return (-1);
    }
  return (0);
}

int		        run(t_game *game_data, t_server_info *server)
{
  struct timeval	cycle_start;
  struct timeval	cycle_finish;
  int			cycles;

  gettimeofday(&cycle_start, NULL);
  while (42)
    {
      gettimeofday(&cycle_finish, NULL);
      cycles = update_timer(server, &cycle_start, &cycle_finish);
      reset_sets(server, game_data);
      if (select(server->fd_max + 1,
		 server->fd_reads, NULL, NULL, server->cycle_end) == -1)
	{
	  perror("Select error: ");
	  return (-1);
	}
      gettimeofday(&cycle_start, NULL);
      if (process(game_data, server, cycles) == -1)
	return (-1);
    }
  return (0);
}
