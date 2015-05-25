/*
** main.c for zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue Apr 28 18:48:21 2015 Oscar Morizet
** Last update Mon May 25 15:55:32 2015 Oscar Morizet
*/

#include		<stdio.h>
#include		<time.h>
#include		<stdlib.h>
#include		"server.h"

void			pre_init(t_game *game_data)
{
  srand(time(NULL));
  game_data->players = NULL;
  game_data->teams = NULL;
}

int			main(int ac, char **av)
{
  t_game		game_data;
  t_server_info		server_info;

  pre_init(&game_data);
  if (!parse_parameters(--ac, ++av, &game_data, &server_info))
    return (-1);
  if (init(&game_data, &server_info) == -1)
    return (-1);
  if (handle_connection(&game_data, &server_info) == -1)
    return (-1);
  return (0);
}
