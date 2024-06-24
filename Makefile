NAME = push_swap

SRCS =	push_swap.c ft_swap.c ft_push.c ft_rotate.c  ft_rrotate.c \
		push_swap_utils.c order.c counter.c errors.c order_utils.c \
		3arg.c

OBJECTS = $(SRCS:.c=.o)

CFLAGS := -Wall -Wextra -Werror
REMOVE = rm -f
CC := cc

all: $(NAME)

$(NAME): $(OBJECTS) libft/libft.a
	$(CC) $(OBJECTS) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft/

.c.o:
		$(CC) $(CFLAGS) -g3 -c $< -o $(<:.c=.o)

clean:
	$(REMOVE) $(OBJECTS)
	make -C libft/ fclean

fclean: clean
	$(REMOVE) $(NAME)
	clear

clear:
	clear

run: re clear
	./$(NAME) "9 7 8 4 6 3 5 2 1"

n: clear
	norminette

leaks: re clear
	valgrind --leak-check=full ./push_swap 9 8 7 6 5 4 3 2 1 0

track: re clear 
	valgrind -s --track-origins=yes ./push_swap 3 2 1 0

t: re clear
	cp push_swap ../testerpushswap
	bash ../testerpushswap/push_swap_test_linux.sh 1 1

re: fclean all
