NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c ft_printf_helper1.c ft_printf_helper2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o test
	./test

.PHONY: all clean fclean re test
