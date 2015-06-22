/*
1;2802;0c1;2802;0c1;2802;0c1;2802;0c** server.h for Zappy in /home/oscar/PSU_2014_zappy/server
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Tue Jun 16 22:37:12 2015 Oscar
** Last update Mon Jun 22 18:51:33 2015 Oscar
*/

#ifndef			SERVER_H_
# define		SERVER_H_

# define		MAX_CONNECTIONS		50
# define		MAX_PLAYERS_PER_TEAM	25
# define		BASE_FOOD		10
# define		FOOD_CONSUMING_CYCLE	126
# define		COMMAND_NB		12
# define		GFX_COMMAND_NB		24
# define		BUFFER_R_SIZE		56
# define		PARAMETERS_BASE		"pxynct"
# define		USAGE			"\n\tUsage : ./server [-p (port)] [-x (map width)] \
[-y (map length)] [-n (team_name_1 team_name_X)] \
[-c (players/team)] [-t (temporal delay)]\n\n"

# include		<stdio.h>
# include		<sys/select.h>
# include		<arpa/inet.h>
# include		"map.h"
# include		"object.h"
# include		"graphix.h"

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

typedef struct			s_standby_client
{
  int				fd;
  struct s_standby_client	*next;
}				t_standby_client;
  
typedef struct		s_coords
{
  int			x;
  int			y;
}			t_coords;

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
  char			name[32];
  int			qt;
  struct s_item		*next;
}			t_item;

typedef struct		s_exec_line t_exec_line;

typedef struct		s_player
{
  int			cycles_to_die;
  int			x;
  int			y;
  int			level;
  int			food;
  int			vision;
  int		        fd;
  int			team_id;
  t_exec_line		*exec_queue;
  t_orientation		orientation;
  t_item		*inventory;
  struct s_player	*next;
}			t_player;

typedef struct		s_team
{
  char			name[56];
  int			id;
  int			players_nb;
  struct s_team		*next;
}			t_team;

typedef struct		s_server_info
{
  struct timeval      	*base_cycle_time;
  struct timeval	*cycle_end;
  int			fd_max;
  int			running_port;
  int			server_fd;
  fd_set		*fd_reads;
}			t_server_info;

typedef			struct s_game t_game;
typedef			int (*t_action_fptr)(t_game *, t_player *, char *);
typedef			int (*t_gfx_action_fptr)(t_game *, t_graphix *, char *);

typedef struct		s_exec_line
{
  char			*parameter;
  t_action_fptr		action;
  int			cycles_before_exec;
  struct s_exec_line	*next;
}			t_exec_line;

typedef struct		s_game
{
  char			*command_names[COMMAND_NB + 1];
  int			command_duration[COMMAND_NB];
  t_action_fptr		command_action[COMMAND_NB + 1];
  char			*gfx_command_names[GFX_COMMAND_NB];
  t_gfx_action_fptr	gfx_command_action[GFX_COMMAND_NB];
  char			*inventory_names[MAX_OBJECTS + 1];
  int			map_size_x;
  int			map_size_y;
  int			players_per_team;
  float			action_delay;
  t_team		*teams;
  t_player		*players;
  t_graphix		*cameras;
  t_standby_client	*standby_clients;
  t_map_case		***map;
}			t_game;

char			*list_inventory(t_player *player);
char			*dump_case(t_game *data, t_map_case *mcase, int index);
char			*get_command_argument(char *cmd);

int			run(t_game *game_data, t_server_info *server);
int			parse_parameters(int, char **, t_game *, t_server_info *);
int			check_if_num(char *);
int			error_print_usage();
int			init(t_game *, t_server_info *);
int			init_server(t_server_info *server);
int			handle_server_requests(t_server_info *server, t_game *game_data);
int			introduce(t_game *data, char *message, int req_fd);
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
int			init_map(t_game *game_data);
int			create_team(t_game *game, char *team_name);
int			remove_client_from_players(t_game *game, int player_fd);
int			execute(t_game *game_data, char *buffer, t_player *player);
int			init_map_case(t_map_case ***map, int x, int y);
int			move_player_to(t_game *game, t_player *player, int new_x, int new_y);
int			init_inventory(t_player *player);
int			add_item_class_to_inventory(t_player *player, char *item_name);
int			init_player(t_game *game_data, t_player *player);
int			get_team_id(t_game *game, char *team_name);
int			err_no_team(int fd);
int			team_get_free_slots(t_game *game, int team_id);
int			err_no_slots_in_team(int fd);
int			finish_player_init(t_game *game_data, t_player *player);
int			check_args(t_game *game, t_server_info *server);
int			init_timer(t_game *game, t_server_info *server);
int			remove_client_from_cameras(t_game *game, int fd);
int			init_player_exec_line(t_player *player);
int			add_new_task_to_queue(t_game *game, t_player *player,
					      t_command command, char *argument);
int			make_cycle(t_game *game);
int			player_process_cycle(t_game *game, t_player *player);
int			update_timer(t_server_info *server,
				     struct timeval *cycle_start,
				     struct timeval *cycle_finish);

void			init_command_names(t_game *game_data);
void			dump_teams(t_game *game);
void			init_command_action(t_game *game_data);
void			clean_out_buffer(char *str);
void			change_item_qt(t_player *player, char *item_name, char evo);
void			change_item_qt(t_player *player, char *item_name, char evo);
void			team_add_slot(t_game *game, int team_id);
void			init_inventory_names(t_game *game_data);
void			init_command_duration(t_game *game_data);
void			map_spawn_items(t_game *game);
void			print_map(t_game *game);
void			reset_sets(t_server_info *server, t_game *game_data);
void			dump_map(t_game *game);
void			dump_case_for_gfx(t_game *game_data, char *str, int x, int y);

t_command		get_command(t_game *game_data, char *cmd);
t_player		*get_player_data(t_game *game_data, int req_fd);
t_player		*add_client_to_players(t_game *game, int player_fd);
t_graphix		*get_camera_data(t_game *game_data, int fd);
t_graphix		*add_client_to_cameras(t_game *game, int fd);

int			gfx_msz(t_game *data, t_graphix *client, char *arg);
int			gfx_bct(t_game *data, t_graphix *client, char *arg);
int			gfx_mct(t_game *data, t_graphix *client, char *arg);
int			gfx_tna(t_game *data, t_graphix *client, char *arg);
int			gfx_pnw(t_game *data, t_graphix *client, int fd);
int			gfx_ppo(t_game *data, t_graphix *client, char *arg);
int			gfx_plv(t_game *data, t_graphix *client, char *arg);
int			gfx_pin(t_game *data, t_graphix *client, char *arg);
int			gfx_pex(t_game *data, t_graphix *client, char *arg);
int			gfx_pbc(t_game *data, t_graphix *client, char *arg);
int			gfx_pic(t_game *data, t_graphix *client, char *arg);
int			gfx_pie(t_game *data, t_graphix *client, char *arg);
int			gfx_pfk(t_game *data, t_graphix *client, char *arg);
int			gfx_pdr(t_game *data, t_graphix *client, char *arg);
int			gfx_pgt(t_game *data, t_graphix *client, char *arg);
int			gfx_pdi(t_game *data, t_graphix *client, char *arg);
int			gfx_enw(t_game *data, t_graphix *client, char *arg);
int			gfx_eht(t_game *data, t_graphix *client, char *arg);
int			gfx_ebo(t_game *data, t_graphix *client, char *arg);
int			gfx_edi(t_game *data, t_graphix *client, char *arg);
int			gfx_sgt(t_game *data, t_graphix *client, char *arg);
int			gfx_seg(t_game *data, t_graphix *client, char *arg);
int			gfx_smg(t_game *data, t_graphix *client, char *arg);
int			gfx_suc(t_game *data, t_graphix *client, char *arg);
int			gfx_sbp(t_game *data, t_graphix *client, char *arg);

#endif			/* !SERVER_H_ */
