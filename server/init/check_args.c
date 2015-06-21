/*
1;2802;0c** check_args.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Fri Jun  5 01:29:08 2015 Oscar
** Last update Sun Jun 21 07:38:38 2015 Oscar
*/

#include	"server.h"

int		check_args(t_game *game, t_server_info *server)
{
  (void) server;
  if (game->action_delay > 10000 || game->action_delay < 1)
    {
      printf("Action delay must be between 1 and 10000\n");
      return (0);
    }
  if (game->players_per_team == 0 || game->players_per_team > MAX_PLAYERS_PER_TEAM)
    {
      printf("Players per teams must be between 1 and %d\n", MAX_PLAYERS_PER_TEAM);
      return (0);
    }
  return (1);
}
