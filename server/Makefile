##
## Makefile for zappy in /home/oscar/rendu/PSU_2014_zappy/server
## 
## Made by Oscar Morizet
## Login   <oscar@epitech.net>
## 
## Started on  Tue Apr 28 18:45:07 2015 Oscar Morizet
## Last update Wed May 20 14:11:38 2015 Oscar Morizet
##

CC		= 	gcc -g3

INCLUDES	=	-I includes/

RM		= 	rm -f

#CFLAGS		=	-W -Wall -Wextra -Werror

NAME 		= 	server

SERVER_ACTIONS	=	actions

SRC		=	main.c \
			init.c \
			argument_parser.c \
			tools.c \
			launch_tools.c \
			server_interactions.c \
			server_commands.c \
			server.c \
			execute.c \
			player_init.c \
			manage_clients.c \
			map.c \
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
			dump_tools.c \

OBJ 		= 	$(SRC:.c=.o)

all: 	     		$(NAME)

$(NAME):		$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

%.o:			%.c
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
clean:	     	
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
