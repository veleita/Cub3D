NAME	= cub3d.a

SRC		= *.c \
		*.h \
		./Printf/*.c \
 		./Printf/ft_printf.h \
 		./Printf/libft/*.c \
 		./Printf/libft/libft.h \

OBJ		= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror
HEADER	= includes/

all: $(NAME)

$(NAME):
	gcc $(CFLAG) -c -I$(HEADER) -I ./Printf/libft -I ./Printf $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o
	rm -f screenshot.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all
