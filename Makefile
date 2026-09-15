CC = cc -Wall -Wextra -Werror

NAME = halfshell
OBJ = halfshell.o
LIBS = src/lib/command.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBS)
	$(CC) -o $@ $(OBJ) -lreadline $(LIBS)

$(OBJ): main.c
	$(CC) -c $< -o $@

$(LIBS):
	$(MAKE) -C src/ all

clean:
	$(MAKE) -C src/ clean

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
