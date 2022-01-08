LIBMLX = mlx_linux/libmlx_Linux.a -Imlx_linux

CFLAGS = -Wall -Wextra -Werror -g3

LFLAGS = -lXext -lX11 -lm -lz

CC = clang

NAME = cub3d

SRC = $(wildcard src/*.c)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I -Imlx_linux -c $< -o $@

$(NAME): $(OBJ)
	make -C mlx_linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -O3 $(LIBMLX) $(LFLAGS)
	
clean:
	make clean -C mlx_linux
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

flemme: re
	make clean

.PHONY: clean fclean all re
