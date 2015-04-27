##
## Makefile for server_zappy in /home/gazzol_j/rendu/PSU_2014_zappy/server
## 
## Made by julien gazzola
## Login   <gazzol_j@epitech.net>
## 
## Started on  Mon Apr 27 11:34:37 2015 julien gazzola
## Last update Mon Apr 27 11:43:06 2015 julien gazzola
##

CC	=	gcc

RM	=	rm -f

NAME	=	serveur

CFLAGS	=	-Wall -Werror -Wextra

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
