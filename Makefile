NAME = push_swap
CFLAGS ?= -Wall -Wextra -Werror
CC = gcc

HEADERFILES = include/push_swap.h

SRC_FILES = main.c parser.c list_functions.c utils.c smallsort.c list_utils.c\
			op_swap.c op_rotate.c op_push.c operations.c\
			bigsort.c move_counter.c\

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix obj/, $(OBJ_FILES))

LIBFT = libft/libft.a
LIBFT_DIR = libft/
PRINTF = ft_printf/printf.a
PRINTF_DIR = ft_printf/

all: $(NAME)

$(NAME): $(OBJS) $(HEADERFILES)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

obj/%.o: src/%.c 
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

norm:
	norminette libft/ ft_printf/ include/ src/

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C$(PRINTF_DIR)

re: fclean all

.PHONY: clean fclean re play