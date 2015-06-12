/*
** inventory_2.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/components
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Fri Jun 12 22:19:59 2015 Oscar
** Last update Fri Jun 12 22:40:23 2015 Oscar
*/

#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>
#include	<stdio.h>
#include	"server.h"

void		init_inventory_names(t_game *game_data)
{ 
  game_data->inventory_names[PLAYER] = strdup("joueur");
  game_data->inventory_names[NOURRITURE] = strdup("nourriture");
  game_data->inventory_names[LINEMATE] = strdup("linemate");
  game_data->inventory_names[DERAUMERE] = strdup("deraumere");
  game_data->inventory_names[SIBUR] = strdup("sibur");
  game_data->inventory_names[MENDIANE] = strdup("mendiane");
  game_data->inventory_names[PHIRAS] = strdup("phiras");
  game_data->inventory_names[THYSTAME] = strdup("thystame");
  game_data->inventory_names[INVALID] = NULL;
}
