##
## Makefile for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
## 
## Made by Oscar Morizet
## Login   <oscar@epitech.net>
## 
## Started on  Tue Jun 16 22:28:04 2015 Oscar Morizet
## Last update Mon Jun 22 14:18:48 2015 Oscar
##

CC		= 	gcc -g3

INCLUDES	=	-I includes/

RM		= 	rm -f

#CFLAGS		=	-W -Wall -Wextra -Werror

NAME 		= 	server

LNAME		=	../server_zappy

SERVER_ACTIONS	=	actions

ACTION_TOOLS	=	action_tools

COMPONENTS	=	components

INIT		=	init

TOOLS		=	tools

TEST		=	test

CORE		=	core

GRAPHIX		=	graphix

SRC		=	$(CORE)/main.c \
			$(INIT)/init.c \
			$(INIT)/argument_parser.c \
			$(INIT)/player_init.c \
			$(INIT)/map_init.c \
			$(INIT)/check_args.c \
			$(CORE)/execute.c \
			$(CORE)/exec_line.c \
			$(CORE)/time.c \
			$(CORE)/server.c \
			$(CORE)/server_interactions.c \
			$(CORE)/server_requesting.c \
			$(CORE)/server_commands.c \
			$(CORE)/players.c \
			$(CORE)/standby_clients.c \
			$(CORE)/quit.c \
			$(COMPONENTS)/map.c \
			$(COMPONENTS)/map_gen.c \
			$(COMPONENTS)/teams.c \
			$(COMPONENTS)/inventory.c \
			$(COMPONENTS)/dump_case.c \
			$(COMPONENTS)/inventory_2.c \
			$(TOOLS)/launch_tools.c \
			$(TOOLS)/tools.c \
			$(TOOLS)/server_run_tools.c \
			$(SERVER_ACTIONS)/introduce_as_player.c \
			$(SERVER_ACTIONS)/introduce_as_graphic.c \
			$(SERVER_ACTIONS)/introduce.c \
			$(SERVER_ACTIONS)/action_avance.c \
			$(SERVER_ACTIONS)/action_gauche.c \
			$(SERVER_ACTIONS)/action_droite.c \
			$(SERVER_ACTIONS)/action_voir.c \
			$(SERVER_ACTIONS)/action_inventaire.c \
			$(SERVER_ACTIONS)/action_prend_objet.c \
			$(SERVER_ACTIONS)/action_pose_objet.c \
			$(SERVER_ACTIONS)/action_fork.c \
			$(SERVER_ACTIONS)/action_connect_nbr.c \
			$(SERVER_ACTIONS)/action_expulse.c \
			$(SERVER_ACTIONS)/action_broadcast.c \
			$(SERVER_ACTIONS)/action_incantation.c \
			$(SERVER_ACTIONS)/err_handling.c \
			$(SERVER_ACTIONS)/$(ACTION_TOOLS)/voir_tools.c \
			$(GRAPHIX)/graphical_clients.c \
			$(GRAPHIX)/init_graphix.c \
			$(GRAPHIX)/graphic_actions_1.c \
			$(GRAPHIX)/graphic_actions_2.c \
			$(GRAPHIX)/graphic_actions_3.c \
			$(GRAPHIX)/graphic_actions_4.c \
			$(GRAPHIX)/graphic_actions_5.c \
			$(GRAPHIX)/graphic_actions_tools.c \
			$(TEST)/dump_tools.c \

OBJ 		= 	$(SRC:.c=.o)

all: 	     		$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(OBJ) -o $(NAME)
			ln -sf $$PWD/$(NAME) $(LNAME)

%.o:			%.c
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
clean:	     	
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)
			$(RM) $(LNAME)

re:			fclean all

.PHONY:			all clean fclean re
