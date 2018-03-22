NAME = fractol

SRC = fractol.c mandel.c julia.c burn_ship.c \
		check.c color1.c move.c image.c

INCLUDE = header.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	make -C ./libft/
	gcc -Wextra -Wall -Werror $(OBJ) -lmlx -framework OpenGL -framework AppKit ./libft/libft.a -o $(NAME)
	
%.o: %.c
	gcc -c -Wextra -Wall -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C ./libft/
	
fclean : clean
	rm -f $(NAME)
	
re: fclean all
