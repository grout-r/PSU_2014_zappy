NAME = client_zappy

all: $(NAME)

$(NAME):
	ln -s $$PWD/client.py ../$(NAME)

clean:
	rm -f ../$(NAME)

fclean: clean

re:
	fclean all

.PHONY: clean re fclean all
