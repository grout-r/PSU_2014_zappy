/*
** err_handling.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server/actions
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 25 16:43:31 2015 Oscar Morizet
** Last update Sun Jul  5 15:32:05 2015 Oscar
*/

#include	<string.h>
#include	<strings.h>
#include	<unistd.h>
#include	"server.h"

int		err_ko(int fd)
{
  char		msg[5];

  bzero(msg, sizeof(char) * 5);
  sprintf(msg, "%s\n", "ko");
  write(fd, msg, strlen(msg));
  return (0);
}
