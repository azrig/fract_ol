NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L/usr/include/minilibx-linux -lmlx -lX11 -lXext -lm

SRCS = fractol.c mandelbrot.c init.c events.c render.c utils.c utils2.c julia.c parse_arg.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
