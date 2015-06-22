NAME = zappy_ai

all: $(NAME)

$(NAME):
	ln -s $$PWD/client.py ../$(NAME)

clean:

fclean: clean
	rm -f ../$(NAME)

re:
	fclean all

.PHONY: clean re fclean all
