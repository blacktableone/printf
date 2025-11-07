NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c ft_printf_helper1.c ft_printf_helper2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) .
	$(AR) $(NAME) $(OBJS) $(LIBFT_DIR)/*.o

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean:
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o test
	./test

.PHONY: all clean fclean re test
