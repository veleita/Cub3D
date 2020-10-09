NAME	= cub3D

SRC		= check.c \
		choose_p.c \
		cub3d.c \
		cub3d.h \
		cubatoi.c \
		drawspr.c \
		error.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_strlen.c \
		get_next_line.c \
		get_next_line_utils.c \
		get_sprite.c \
		init.c \
		keys.c \
		make_txt.c \
		move.c \
		parse.c \
		parse_map.c \
		pl_init.c \
		raycasting.c \
		raycasting_2.c \
		screenshot.c \
		ft_strncmp.c \

OBJ		= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAG) -o $(NAME) $(SRC) 

clean:
	rm -f *.o
	rm -f screenshot.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all
