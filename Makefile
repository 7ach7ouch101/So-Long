NAME = so_long

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = so_long.c tools.c tools2.c\

OBJS = $(SRCS:.c=.o)

MLX_API = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJS) so_long.h
	@cc $(CFLAGS) $(MLX_API) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@