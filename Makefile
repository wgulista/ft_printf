.PHONY: all, clean, fclean, re

NAME = ft_printf.a
HEADER = ft_printf.h
LIBFT = libft.a
CFLAGS = -Wall -Wextra -Werror
SRC_NAME = calc_none_space.c check_function.c struct_init.c conv_string.c \
			conv_pointer.c conv_integer.c conv_char.c space.c update_int.c \
			ft_printf.c
OBJ_PATH = obj
SRC_PATH = srcs
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "\033[32mCompiling" [ $(NAME) ]"\033[0m"

$(addprefix $(OBJ_PATH)/, %.o): $(addprefix $(SRC_PATH)/, %.c)
		@mkdir -p $(OBJ_PATH)
		@gcc $(CFLAGS) -I ./includes/$(HEADER) -o $@ -c $^
		@echo "\033[33mLinking" [ $< ] "\033[0m"

$(LIBFT):
		@make -C ./libft/
		@echo "\033[32mCompiling" [ $(LIBFT) ]"\033[0m"

clean:
		@rm -f $(OBJ)
		@make clean -C ./libft/
		@echo "\033[31mCleaning" [ $(NAME) ] "...\033[0m"

fclean: clean
		@rm -f $(NAME)
		@make fclean -C ./libft/
		@echo "\033[31mDelete" [ $(NAME) ] "\033[0m"

re: fclean all
