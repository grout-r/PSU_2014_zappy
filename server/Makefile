##
## Makefile for zappy in /home/oscar/rendu/PSU_2014_zappy/server
## 
## Made by Oscar Morizet
## Login   <oscar@epitech.net>
## 
## Started on  Tue Apr 28 18:45:07 2015 Oscar Morizet
## Last update Tue Apr 28 21:25:08 2015 Oscar Morizet
##

CC		= 	gcc

INCLUDES	=	-I includes/

RM		= 	rm -f

CFLAGS		=	-W -Wall -Wextra -Werror

NAME 		= 	server

SRC		=	main.c \
			init.c \
			argument_parser.c \
			tools.c \
			launch_tools.c \
			server.c

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
