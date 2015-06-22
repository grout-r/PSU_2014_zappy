/*
1;2802;0c1;2802;0c1;2802;0c** init_graphix.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Mon Jun 22 07:36:42 2015 Oscar
** Last update Mon Jun 22 08:36:33 2015 Oscar
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	"server.h"

void		init_gfx_command_names(t_game *game)
{
  game->gfx_command_names[MSZ] = strdup("msz");
  game->gfx_command_names[BCT] = strdup("bct");
  game->gfx_command_names[TNA] = strdup("tna");
  game->gfx_command_names[PNW] = strdup("pnw");
  game->gfx_command_names[PPO] = strdup("ppo");
  game->gfx_command_names[PLV] = strdup("plv");
  game->gfx_command_names[PIN] = strdup("pin");
  game->gfx_command_names[PEX] = strdup("pex");
  game->gfx_command_names[PBC] = strdup("pbc");
  game->gfx_command_names[PIC] = strdup("pic");
  game->gfx_command_names[PIE] = strdup("pie");
  game->gfx_command_names[PFK] = strdup("pfk");
  game->gfx_command_names[PDR] = strdup("pdr");
  game->gfx_command_names[PGT] = strdup("pgt");
  game->gfx_command_names[PDI] = strdup("pdi");
  game->gfx_command_names[ENW] = strdup("enw");
  game->gfx_command_names[EHT] = strdup("eht");
  game->gfx_command_names[EBO] = strdup("ebo");
  game->gfx_command_names[EDI] = strdup("edi");
  game->gfx_command_names[SGT] = strdup("sgt");
  game->gfx_command_names[SEG] = strdup("seg");
  game->gfx_command_names[SMG] = strdup("smg");
  game->gfx_command_names[SBP] = strdup("sbp");
  game->gfx_command_names[SUC] = NULL;
}

void		init_gfx_command_action(t_game *game)
{
  game->gfx_command_action[MSZ] = &gfx_msz;
  game->gfx_command_action[BCT] = &gfx_bct;
  game->gfx_command_action[TNA] = &gfx_tna;
  game->gfx_command_action[PNW] = &gfx_pnw;
  game->gfx_command_action[PPO] = &gfx_ppo;
  game->gfx_command_action[PLV] = &gfx_plv;
  game->gfx_command_action[PIN] = &gfx_pin;
  game->gfx_command_action[PEX] = &gfx_pex;
  game->gfx_command_action[PBC] = &gfx_pbc;
  game->gfx_command_action[PIC] = &gfx_pic;
  game->gfx_command_action[PIE] = &gfx_pie;
  game->gfx_command_action[PFK] = &gfx_pfk;
  game->gfx_command_action[PDR] = &gfx_pdr;
  game->gfx_command_action[PGT] = &gfx_pgt;
  game->gfx_command_action[PDI] = &gfx_pdi;
  game->gfx_command_action[ENW] = &gfx_enw;
  game->gfx_command_action[EHT] = &gfx_eht;
  game->gfx_command_action[EBO] = &gfx_ebo;
  game->gfx_command_action[EDI] = &gfx_edi;
  game->gfx_command_action[SGT] = &gfx_sgt;
  game->gfx_command_action[SEG] = &gfx_seg;
  game->gfx_command_action[SMG] = &gfx_smg;
  game->gfx_command_action[SBP] = &gfx_sbp;
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
