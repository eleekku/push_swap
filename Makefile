LIBFT	=	libft/libft.a libft/ft_printf/libftprintf.a
NAME	=	push_swap

SRCS	=	push_swap.c \
			operations.c \
			operations_raw.c \
			algo_utils.c \
			simple_algo.c \
			check_args.c \
			
OFILES	=	$(SRCS:.c=.o)

CC		=	@cc
RM		=	@-rm -f
CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) ${OFILES}
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C ./libft
	@make bonus -C ./libft

%.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@

clean:
		@make clean -C libft
		$(RM) $(OFILES)
	
fclean: clean
		@make fclean -C libft
		$(RM) $(NAME) $(OFILES)

re: fclean all

.PHONY: all clean fclean re