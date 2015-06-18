##
## Makefile for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui
## 
## Made by grout_r
## Login   <roman@epitech.net>
## 
## Started on  Mon Apr 27 11:34:18 2015 grout_r
## Last update Tue Jun 16 09:38:17 2015 grout_r
##

CC		= 	g++ -g3

INCLUDES	=	-I includes/

RM		= 	rm -f

CXXFLAGS	=	-W -Wall -Wextra -Werror

SFML_LDFLAGS    =       -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

NAME 		= 	zappy_gui

SRC		=	src/main.cpp \
			src/Graphics.cpp \
			src/Event.cpp \
			src/Camera.cpp \
			src/Network.cpp \
			src/Player.cpp \
			src/Exception.cpp \
			src/Map.cpp

OBJ 		= 	$(SRC:.cpp=.o)

all: 	     		$(NAME)

$(NAME):		$(OBJ)
			$(CC)  $(OBJ) -o $(NAME) $(SFML_LDFLAGS)

%.o:			%.cpp
			$(CC) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<
clean:	     	
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
