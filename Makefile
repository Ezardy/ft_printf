IFLAGS=-Ilibft
CFLAGS=-Wall -Wextra -Werror
LFLAGS=-Llibft

BUILD_DIR=build

MODULES=
OBJ=$(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(MODULES)))

.PHONY: all re clean fclean libft.a

all: libftprintf.a

libftprintf.a: $(BUILD_DIR) $(OBJ)
	ar rcs $(LFLAGS) $@ libft.a

libft.a:
	make -c libft all

$(BUILD_DIR)/%.o: %.c
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
