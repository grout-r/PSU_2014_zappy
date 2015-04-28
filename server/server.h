/*
** server.h for zappy in /home/verove_j/rendu/PSU_2014_zappy/server
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Tue Apr 28 12:55:29 2015 Jordan Verove
** Last update Tue Apr 28 14:07:32 2015 Jordan Verove
*/

#ifndef SERVER_H_
# define SERVER_H_

typedef enum		e_orientation
  {
    LEFT,
    RIGHT,
    UP,
    DOWN
  }

typedef struct		s_server_info
{
  int			server_fd;
}			t_server_info;

typedef struct		s_game
{
  char			**team_names;
  int			map_size_x;
  int			map_size_y;
  int			players_per_teams;
  int			action_delay;
}			t_game;

typedef struct		s_item
{
  int			linemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			t_item;

typedef struct		s_player
{
  int			x;
  int			y;
  int			level;
  int			food;
  int			vision;
  int			player_fd;
  char			*team;
  e_orientation		orientation;
  t_item		inventory;
}			t_player;

#endif /* !SERVER_H_ */
