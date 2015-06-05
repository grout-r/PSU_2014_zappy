/*
1;2802;0c** check_args.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Fri Jun  5 01:29:08 2015 Oscar
** Last update Fri Jun  5 01:32:50 2015 Oscar
*/

#include	"server.h"

int		check_args(t_game *game, t_server_info *server)
{
  if (game->action_delay > 10000 || game->action_delay < 1)
    {
      printf("Action delay must be between 1 and 10000\n");
      return (0);
    }
  return (1);
}
