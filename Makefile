IFLAGS=-Ilibft
CFLAGS=-Wall -Wextra -Werror
LFLAGS=-Llibft

.PHONY: all re clean fclean libft.a

all: libftprintf.a

libftprintf.a

libft.a:
	make -c libft all
