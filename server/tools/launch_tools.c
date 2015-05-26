/*
** launch_tools.c for zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue Apr 28 21:24:02 2015 Oscar Morizet
** Last update Tue Apr 28 21:25:25 2015 Oscar Morizet
*/

#include	<stdio.h>
#include	"server.h"
#include	"misc.h"

int		error_print_usage()
{
  fprintf(stderr, "%s%s%s", COLOR_RED_ON, USAGE, COLOR_OFF);
  return (0);
}
