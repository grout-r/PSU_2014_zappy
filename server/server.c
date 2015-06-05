/*
** server.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Fri Jun  5 17:39:08 2015 Oscar
** Last update Fri Jun  5 17:44:19 2015 Oscar
*/

#include		<sys/select.h>
#include		<sys/time.h>
#include		<stdio.h>
#include		<unistd.h>
#include		"server.h"
#include		"timer.h"

void			reset_sets(t_server_info *server, t_game *game_data)
{
  t_player		*tmp;

  tmp = game_data->players;
  FD_ZERO(server->fd_reads);
  FD_SET(server->server_fd, server->fd_reads);
  server->fd_max = server->server_fd;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, server->fd_reads);
      if (tmp->fd > server->fd_max)
	server->fd_max = tmp->fd;
      tmp = tmp->next;
    }
}

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
  usleep(5500);
  return (0);
  while (i != cycle_nb)
    {
      if (make_cycle(game, server) == -1)
	return (-1);
      ++i;
    }
  return (0);
}

int			handle_connection(t_game *game_data, t_server_info *server)
{
  struct timeval	timing[2];

  gettimeofday(&timing[START_TIMER], NULL);
  printf("start %ld\n", timing[START_TIMER].tv_usec);
  while (42)
    {
      gettimeofday(&timing[END_TIMER], NULL);
      printf("end %ld\n", timing[END_TIMER].tv_usec);
      update_timer(game_data, server, timing);
      reset_sets(server, game_data);
      gettimeofday(&timing[START_TIMER], NULL);
      printf("start %ld\n", timing[START_TIMER].tv_usec);
      if (select(server->fd_max + 1,
		 server->fd_reads, NULL, NULL, server->cycle_end) == -1)
	{
	  perror("Select error: ");
	  return (-1);
	}
      if (server->cycle_end->tv_usec == 0)
	{
	  usleep(9999);
	  //if (cyclify(1, game_data, server) == -1)
	  //return (-1);
	}
      //else if (handle_server_interactions(server, game_data) == -1)
      //return (-1);
    }
  return (0);
}
