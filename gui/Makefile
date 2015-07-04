##
## Makefile for zappy in /home/roman/Documents/dev/PSU_2014_zappy/gui
## 
## Made by grout_r
## Login   <roman@epitech.net>
## 
## Started on  Mon Apr 27 11:34:18 2015 grout_r
## Last update Wed Jul  1 17:32:56 2015 grout_r
##

CC		= 	g++

INCLUDES	=	-I includes/

RM		= 	rm -f

CXXFLAGS	=	-W -Wall -Wextra -Werror

SFML_LDFLAGS    =       -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

NAME 		= 	zappy_gui

ROOTNAME	=	../zappy_gui

SRC		=	src/main.cpp \
			src/Graphics.cpp \
			src/Event.cpp \
			src/Camera.cpp \
			src/Network.cpp \
			src/Player.cpp \
			src/Exception.cpp \
			src/Map.cpp \
			src/Case.cpp \
			src/Egg.cpp \

OBJ 		= 	$(SRC:.cpp=.o)

all: 	     		$(NAME)

$(NAME):		$(OBJ)
			$(CC)  $(OBJ) -o $(NAME) $(SFML_LDFLAGS)
			cp $$PWD/$(NAME) $(ROOTNAME)

%.o:			%.cpp
			$(CC) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<
clean:	     	
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)
			$(RM) $(ROOTNAME)

re:			fclean all

.PHONY:			all clean fclean re
