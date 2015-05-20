/*
** main.c for zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue Apr 28 18:48:21 2015 Oscar Morizet
** Last update Wed May 20 15:06:46 2015 Oscar Morizet
*/

#include		<stdio.h>
#include		"server.h"

int			main(int ac, char **av)
{
  t_game		game_data;
  t_server_info		server_info;

  if (!parse_parameters(--ac, ++av, &game_data, &server_info))
    return (-1);
  if (init(&game_data, &server_info) == -1)
    return (-1);

  add_client_to_players(&game_data, 5555);
  move_player_to(&game_data, game_data.players, 3, 2);
  dump_map(&game_data);

  /*
  if (handle_connection(&game_data, &server_info) == -1)
    return (-1);
  */
  return (0);
}
