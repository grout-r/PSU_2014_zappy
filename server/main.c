/*
** main.c for zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue Apr 28 18:48:21 2015 Oscar Morizet
** Last update Tue Apr 28 21:35:08 2015 Oscar Morizet
*/

#include		<stdio.h>
#include		"server.h"

int			main(int ac, char **av)
{
  t_game		game_data;
  t_server_info		server_info;

  if (!parse_parameters(++ac, ++av, &game_data, &server_info))
    return (-1);
  if (!init(&game_data, &server_info))
    return (-1);

  /*
  ** Print args you entered
  */

  printf("port = %d\n", server_info.running_port);
  printf("mapX = %d\n", game_data.map_size_x);
  printf("mapY = %d\n", game_data.map_size_y);
  printf("players per team = %d\n", game_data.players_per_team);
  printf("action delay = %d\n", game_data.action_delay);

  /*********/

  return (0);
}
