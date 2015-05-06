##
## Makefile for zappy in /home/oscar/rendu/PSU_2014_zappy/server
## 
## Made by Oscar Morizet
## Login   <oscar@epitech.net>
## 
## Started on  Tue Apr 28 18:45:07 2015 Oscar Morizet
## Last update Mon May  4 23:44:21 2015 Oscar Morizet
##

CC		= 	gcc -g3

INCLUDES	=	-I includes/

RM		= 	rm -f

#CFLAGS		=	-W -Wall -Wextra -Werror

NAME 		= 	server

SRC		=	main.c \
			init.c \
			argument_parser.c \
			tools.c \
			launch_tools.c \
			server_interactions.c \
			server.c \
			execute.c \
			manage_clients.c \

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
