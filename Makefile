NAME = so_long

CFLAGS = #-Wall -Wextra -Werror

RM = rm -f

SRCS = so_long.c parser.c parser2.c tools.c tools2.c tools3.c tools4.c\

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