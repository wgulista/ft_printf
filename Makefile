NAME = libftprintf.a
HEADER = ft_printf.h
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror

SRC = conv_c.c conv_wc.c conv_s.c conv_ws.c conv_p.c \
		conv_o.c conv_go.c conv_u.c conv_gu.c conv_x.c conv_gx.c \
		conv_id.c conv_gd.c helpers.c conv_parser.c non_conv.c \
		get_flag.c get_prec.c get_size.c get_width.c ft_printf.c env.c \
		conv_wc2.c

OBJ_PATH = obj
SRC_PATH = srcs
INC = -I ./libft/includes -I ./includes

CFLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		@make -C ./libft/
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@libtool -static -o libftprintf.a $(LIBFT) ./libftprintf.a
		@printf "\r\033[32mCompiling [ $(NAME) ] \033[0m\033[K"

$(addprefix $(OBJ_PATH)/, %.o): $(addprefix $(SRC_PATH)/, %.c)
		@mkdir -p $(OBJ_PATH)
		@gcc $(CFLAGS) -o $@ -c $^ $(INC)
		@printf "\r\033[33mLinking [ $< ] ... \033[0m\033[K"

clean:
		@rm -fv $(OBJ)
		@rm -Rf $(OBJ_PATH)
		@make clean -C ./libft/
		@printf "\r\033[31mCleaning [ $(NAME) ] ...\033[0m\033[K"

fclean: clean
		@rm -fv $(NAME)
		@make fclean -C ./libft/
		@printf "\r\033[31mDelete [ $(NAME) ] \033[0m\033[K"

re: fclean all

.PHONY: all clean fclean re
