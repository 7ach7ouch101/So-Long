NAME = so_long

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = so_long.c parser.c parser2.c tools.c tools2.c tools3.c tools4.c\

MLX_API = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(SRCS) so_long.h
	@cc $(CFLAGS) $(MLX_API) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all