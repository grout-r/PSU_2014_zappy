/*
** init_graphix.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 07:36:42 2015 Oscar
** Last update Tue Jun 23 08:50:09 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"server.h"

void		init_gfx_command_names(t_game *game)
{
  game->gfx_command_names[MSZ] = strdup("msz");
  game->gfx_command_names[BCT] = strdup("bct");
  game->gfx_command_names[MCT] = strdup("mct");
  game->gfx_command_names[TNA] = strdup("tna");
  game->gfx_command_names[PPO] = strdup("ppo");
  game->gfx_command_names[PLV] = strdup("plv");
  game->gfx_command_names[PIN] = strdup("pin");
  game->gfx_command_names[SGT] = strdup("sgt");
  game->gfx_command_names[SST] = strdup("sst");
  game->gfx_command_names[SUC] = NULL;
}

void		init_gfx_command_action(t_game *game)
{
  game->gfx_command_action[MSZ] = &gfx_msz;
  game->gfx_command_action[BCT] = &gfx_bct;
  game->gfx_command_action[MCT] = &gfx_mct;
  game->gfx_command_action[TNA] = &gfx_tna;
  game->gfx_command_action[PPO] = &gfx_ppo;
  game->gfx_command_action[PLV] = &gfx_plv;
  game->gfx_command_action[PIN] = &gfx_pin;
  game->gfx_command_action[SGT] = &gfx_sgt;
  game->gfx_command_action[SST] = &gfx_seg;
  game->gfx_command_action[SUC] = &gfx_sbp;
}

t_gfx_command	get_gfx_command(t_game *game_data, char *cmd)
{
  int		i;

  i = 0;
  while (game_data->gfx_command_names[i] &&
	 strncmp(cmd, game_data->gfx_command_names[i],
		 strlen(game_data->gfx_command_names[i])) != 0)
    ++i;
  return ((t_gfx_command) i);
}
