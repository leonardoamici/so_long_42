NAME = so_long

LIBFT = Libft/libft.a

MINILIBX = minilibx-linux/libmlx.a

SRC =	source/main.c \
	source/deal_imgs.c \
	source/deal_map.c \
	source/deal_key.c \
	source/ft_check_map.c \
	source/ft_floodfill.c \
	source/sl_utils.c
	
FLAGS = -no-pie -Wall -Werror -Wextra -g

LINKS = -lm -lX11 -lXext

all: $(NAME)

$(NAME): libcomp comp

norm:
		@cd source/ && norminette

libcomp:
		@make -C Libft
	
comp:
	gcc $(FLAGS) $(SRC) $(MINILIBX) $(LIBFT) $(LINKS) -o $(NAME)
            
libclean:
		@make clean -C Libft
		
clean:		libclean

libfclean:
		@make fclean -C Libft

fclean:   	clean libfclean
		rm -rf $(NAME)
		
re: fclean all

.SILENT:
