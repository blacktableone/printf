NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(Name): $(OBJS)
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

.PHONY: all clean fclean re


