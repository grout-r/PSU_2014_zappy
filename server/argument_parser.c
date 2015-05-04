/*
** argument_parser.c for zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Tue Apr 28 19:42:16 2015 Oscar Morizet
** Last update Mon May  4 09:48:38 2015 Jordan Verove
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"server.h"
#include	"misc.h"

char	        what_parameter(char *param)
{
  char		flags[] = PARAMETERS_BASE;
  char		test[3];
  int		f;

  f = 0;
  test[0] = '-';
  test[2] = '\0';
  while (flags[f])
    {
      test[1] = flags[f];
      if (!strcmp(test, param))
	return (flags[f]);
      ++f;
    }
  return (0);
}

void		fill_parse_struct(char p, t_parse_arg *tmp, char **parameters)
{
  if (p == 'p')
    strcpy(tmp->running_port, *parameters);
  else if (p == 'x')
    strcpy(tmp->map_size_x, *parameters);
  else if (p == 'y')
    strcpy(tmp->map_size_y, *parameters);
  else if (p == 'c')
    strcpy(tmp->players_per_team, *parameters);
  else if (p == 't')
    strcpy(tmp->action_delay, *parameters);
}

int		argument_checker(t_parse_arg *tmp, t_game *game_properties,
				 t_server_info *server_info)
{
  if (*tmp->running_port == 0 || *tmp->map_size_x == 0 ||
      *tmp->map_size_y == 0 || *tmp->players_per_team == 0 ||
      *tmp->action_delay == 0)
    {
      return (error_print_usage());
    }
  if ((!check_if_num(tmp->running_port)) || (!check_if_num(tmp->map_size_x))
      || (!check_if_num(tmp->map_size_y)) ||
      (!check_if_num(tmp->players_per_team)) ||
      (!check_if_num(tmp->action_delay)))
    {
      return (error_print_usage());
    }
  server_info->running_port = atoi(tmp->running_port);
  game_properties->map_size_x = atoi(tmp->map_size_x);
  game_properties->map_size_y = atoi(tmp->map_size_y);
  game_properties->players_per_team = atoi(tmp->players_per_team);
  game_properties->action_delay = atoi(tmp->action_delay);
  return (1);
}

int		parse_parameters(int parameters_nb, char **parameters,
				 t_game	*game_properties, t_server_info *server_info)
{
  t_parse_arg	tmp;
  char		p;

  bzero(&tmp, sizeof(t_parse_arg));
  if (parameters_nb < 13)
    return (error_print_usage());
  while (*parameters)
    {
      if ((p = what_parameter(*parameters)) == 0 || !(*++parameters))
	return (error_print_usage());
      if (p == 'n')
	{
	  while (*parameters && !what_parameter(*parameters))
	    {
	      printf("add team %s\n", *parameters);
	      ++parameters;
	    }
	}
      else
	{
	  fill_parse_struct(p, &tmp, parameters);
	  ++parameters;
	}
    }
  return (argument_checker(&tmp, game_properties, server_info));
}
