NAME = so_long

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = so_long.c parser.c parser2.c tools.c tools2.c tools3.c tools4.c

OBJ = $(SRCS:.c=.o)

MLX_API = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ) so_long.h
	@cc $(CFLAGS) $(MLX_API) $(OBJ) -o $(NAME)

%.o: %.c so_long.h
	@cc $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all