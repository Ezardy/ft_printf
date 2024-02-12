HEADERS_DIR=./headers
LIBFT_DIR=./libft

IFLAGS=-I$(LIBFT_DIR) -I$(HEADERS_DIR)
CFLAGS=-Wall -Wextra -Werror -g

BUILD_DIR=build

MODULES=ft_putnbr_base options_parser output print_int print_string ft_printf
OBJ=$(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(MODULES)))

.PHONY: all re clean fclean bonus

all: libftprintf.a

bonus: all

libftprintf.a: $(LIBFT_DIR)/libft.a $(BUILD_DIR) $(OBJ)
	cp $(LIBFT_DIR)/libft.a $@
	ar rcs $@ $(OBJ)

$(LIBFT_DIR)/libft.a: $(LIBFT_DIR)/libft.h
	make -C libft all

$(BUILD_DIR)/%.o: %.c Makefile $(HEADERS_DIR)/utilities.h $(LIBFT_DIR)/libft.h ft_printf.h
	cc $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	rm -rf build
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f libftprintf.a
