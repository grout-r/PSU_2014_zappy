/*
** err_handling.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 25 16:43:31 2015 Oscar Morizet
** Last update Mon May 25 16:58:14 2015 Oscar Morizet
*/

#include	<string.h>
#include	<strings.h>
#include	"server.h"

int		err_no_team(t_player *player)
{
  char		msg[512];

  bzero(msg, sizeof(char) * 512);
  sprintf(msg, "%s\n", "Cette équipe n'éxiste pas !");
  write(player->fd, msg, strlen(msg));
  return (0);
}

int		err_no_slots_in_team(t_player *player)
{
  char		msg[512];

  bzero(msg, sizeof(char) * 512);
  sprintf(msg, "%s\n", "Il n'y à plus de places \
libres dans cette équipe ! Veuillez patienter ou \
choisir une autre équipe.");
  write(player->fd, msg, strlen(msg));
  return (0);
}
