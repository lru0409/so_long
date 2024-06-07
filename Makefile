NAME = so_long

MANDATORY_SRCS = $(wildcard mandatory/*.c)
BONUS_SRCS = $(wildcard bonus/*.c)

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

ifdef BONUS
	OBJS = $(BONUS_OBJS)
else
	OBJS = $(MANDATORY_OBJS)
endif

all : $(NAME)

bonus :
	make BONUS=1

$(NAME) : $(OBJS)
	make -C libft all
	make -C mlx all
	$(CC) $(FLAGS) -fsanitize=address -g3 -o $(NAME) $(OBJS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework Appkit

%.o : %.c
	$(CC) $(FLAGS) -Imlx -c $^ -o $@

clean :
	make -C libft clean
	make -C mlx clean
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus