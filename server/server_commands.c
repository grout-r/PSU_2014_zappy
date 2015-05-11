/*
** server_commands.c for server_commands.c in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:00:41 2015 Oscar Morizet
** Last update Mon May 11 16:40:55 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"server.h"

void		init_command_names(t_game *game_data)
{
  game_data->command_names[AVANCE] = strdup("avance");
  game_data->command_names[DROITE] = strdup("droite");
  game_data->command_names[GAUCHE] = strdup("gauche");
  game_data->command_names[VOIR] = strdup("voir");
  game_data->command_names[INVENTAIRE] = strdup("inventaire");
  game_data->command_names[PREND_OBJET] = strdup("prend objet");
  game_data->command_names[POSE_OBJET] = strdup("pose objet");
  game_data->command_names[EXPULSE] = strdup("expulse");
  game_data->command_names[BROADCAST] = strdup("broadcast");
  game_data->command_names[INCANTATION] = strdup("incantation");
  game_data->command_names[FORK] = strdup("fork");
  game_data->command_names[CONNECT_NBR] = strdup("connect_nbr");
  game_data->command_names[INVALID] = NULL;
}

void		init_command_action(t_game *game_data)
{
  game_data->command_action[AVANCE] = &action_avance;
  game_data->command_action[DROITE] = &action_droite;
  game_data->command_action[GAUCHE] = &action_gauche;
  game_data->command_action[VOIR] = action_voir;
  game_data->command_action[INVENTAIRE] = &action_inventaire;
  game_data->command_action[PREND_OBJET] = &action_prend_objet;
  game_data->command_action[POSE_OBJET] = &action_pose_objet;
  game_data->command_action[EXPULSE] = &action_expulse;
  game_data->command_action[BROADCAST] = &action_broadcast;
  game_data->command_action[INCANTATION] = &action_incantation;
  game_data->command_action[FORK] = &action_fork;
  game_data->command_action[CONNECT_NBR] = &action_connect_nbr;
  game_data->command_action[INVALID] = NULL;
}

t_command	get_command(t_game *game_data, char *cmd)
{
  int		i;

  i = 0;
  while (game_data->command_names[i] &&
	 strcmp(cmd, game_data->command_names[i]) != 0)
    ++i;
  return ((t_command) i);
}

