/*
1;2802;0c1;2802;0c** server_commands.c for server_commands.c in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 11 16:00:41 2015 Oscar Morizet
** Last update Mon Jun 22 07:42:07 2015 Oscar
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
  game_data->command_names[PREND_OBJET] = strdup("prend");
  game_data->command_names[POSE_OBJET] = strdup("pose");
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

void		init_command_duration(t_game *game_data)
{
  game_data->command_duration[AVANCE] = 7;
  game_data->command_duration[DROITE] = 7;
  game_data->command_duration[GAUCHE] = 7;
  game_data->command_duration[VOIR] = 7;
  game_data->command_duration[INVENTAIRE] = 1;
  game_data->command_duration[PREND_OBJET] = 7;
  game_data->command_duration[POSE_OBJET] = 7;
  game_data->command_duration[EXPULSE] = 7;
  game_data->command_duration[BROADCAST] = 7;
  game_data->command_duration[INCANTATION] = 300;
  game_data->command_duration[FORK] = 42;
  game_data->command_duration[CONNECT_NBR] = 0;
}


t_command	get_command(t_game *game_data, char *cmd)
{
  int		i;

  i = 0;
  while (game_data->command_names[i] &&
	 strncmp(cmd, game_data->command_names[i],
		 strlen(game_data->command_names[i])) != 0)
    ++i;
  return ((t_command) i);
}

char		*get_command_argument(char *cmd)
{
  while (*cmd && *cmd != ' ')
    ++cmd;
  if (*cmd == ' ')
    ++cmd;
  return (cmd);
}
