/*
** server.h for zappy in /home/verove_j/rendu/PSU_2014_zappy/server
** 
** Made by Jordan Verove
** Login   <verove_j@epitech.net>
** 
** Started on  Tue Apr 28 12:55:29 2015 Jordan Verove
** Last update Mon May 18 18:04:18 2015 Oscar Morizet
*/

#ifndef			SERVER_H_
# define		SERVER_H_

# define		MAX_CONNECTIONS 50
# define		COMMAND_NB	12
# define		BUFFER_R_SIZE	56
# define		PARAMETERS_BASE	"pxynct"
# define		USAGE "\n\tUsage : ./server [-p (port)] [-x (map width)] \
[-y (map length)] [-n (team_name_1 team_name_X)] \
[-c (players/team)] [-t (temporal delay)]\n\n"

# include		<stdio.h>
# include		<sys/select.h>
# include		<arpa/inet.h>
# include		"map.h"

typedef enum		e_orientation
  {
    LEFT = 0,
    UP, 
    RIGHT,
    DOWN
  }			t_orientation;

typedef enum		e_command
  {
    AVANCE = 0,
    DROITE,
    GAUCHE,
    VOIR,
    INVENTAIRE,
    PREND_OBJET,
    POSE_OBJET,
    EXPULSE,
    BROADCAST,
    INCANTATION,
    FORK,
    CONNECT_NBR,
    INVALID
  }			t_command;

typedef struct		s_parse_arg
{
  char		        running_port[56];
  char			map_size_x[56];
  char			map_size_y[56];
  char		        players_per_team[56];
  char		        action_delay[56];
}			t_parse_arg;

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
  t_orientation		orientation;
  t_item		inventory;
  struct s_player	*next;
}			t_player;

typedef struct		s_server_info
{
  int			fd_max;
  int			running_port;
  int			server_fd;
  fd_set		*fd_reads;
}			t_server_info;

typedef			struct s_game t_game;
typedef			int (*action_fptr)(t_game *, t_player *, char *);

typedef struct		s_game
{
  char			*command_names[COMMAND_NB + 1];
  action_fptr		command_action[COMMAND_NB + 1];
  int			map_size_x;
  int			map_size_y;
  int			players_per_team;
  int			action_delay;
  t_player		*players;
  t_map_case		***map;
}			t_game;

int			handle_connection(t_game *game_data, t_server_info *server);
int			parse_parameters(int, char **, t_game *, t_server_info *);
int			check_if_num(char *);
int			error_print_usage();
int			init(t_game *, t_server_info *);
int			init_server(t_server_info *server);
int			handle_server_interactions(t_server_info *server, t_game *game_data);

int			action_avance(t_game *data, t_player *player_data, char *arg);
int			action_droite(t_game *data, t_player *player_data, char *arg);
int			action_gauche(t_game *data, t_player *player_data, char *arg);
int			action_voir(t_game *data, t_player *player_data, char *arg);
int			action_inventaire(t_game *data, t_player *player_data, char *arg);
int			action_prend_objet(t_game *data, t_player *player_data, char *arg);
int			action_pose_objet(t_game *data, t_player *player_data, char *arg);
int			action_expulse(t_game *data, t_player *player_data, char *arg);
int			action_broadcast(t_game *data, t_player *player_data, char *arg);
int			action_incantation(t_game *data, t_player *player_data, char *arg);
int			action_gauche(t_game *data, t_player *player_data, char *arg);
int			action_fork(t_game *data, t_player *player_data, char *arg);
int			action_connect_nbr(t_game *data, t_player *player_data, char *arg);

void			init_command_names(t_game *game_data);

#endif			/* !SERVER_H_ */
