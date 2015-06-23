/*
** main.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/core
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Tue Jun 23 08:41:57 2015 Oscar
** Last update Tue Jun 23 11:37:50 2015 Oscar
*/

#include		<stdio.h>
#include		<time.h>
#include		<stdlib.h>
#include		"server.h"

void			pre_init(t_game *game_data)
{
  srand(time(NULL));
  game_data->eggs = NULL;
  game_data->standby_clients = NULL;
  game_data->players = NULL;
  game_data->cameras = NULL;
  game_data->teams = NULL;
}

int			main(int ac, char **av)
{
  t_game		game_data;
  t_server_info		server_info;

  pre_init(&game_data);
  if (!parse_parameters(--ac, ++av, &game_data, &server_info))
    return (-1);
  if (!check_args(&game_data, &server_info))
    return (-1);
  if (init(&game_data, &server_info) == -1)
    return (-1);
  if (run(&game_data, &server_info) == -1)
    return (-1);
  return (0);
}
