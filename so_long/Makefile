NAME			= so_long
BNAME			= so_long_bonus
CC 		    	= gcc
FLAGS			= -framework OpenGL -framework AppKit -Wall -Wextra -Werror
SRC         	= $(wildcard sources/*.c)
B_SRC			= $(wildcard bonus/*.c)
OBJ         	= $(SRC:.c=.o)
B_OBJ			= $(B_SRC:.c=.o)
MINILIBX		= ./lib/minilibx/libmlx.a
PRINTF			= ./lib/printf/libftprintf.a
LIBFT			= ./lib/libft/libft.a

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJ) $(PRINTF) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(MINILIBX) $(LIBFT) $(PRINTF) -o $(NAME)
	
bonus: $(BNAME)

$(BNAME): $(MINILIBX) $(B_OBJ) $(PRINTF) $(LIBFT)
	$(CC) $(FLAGS) $(B_OBJ) $(MINILIBX) $(LIBFT) $(PRINTF) -o $(BNAME)

$(MINILIBX):
			$(MAKE) -C ./lib/minilibx
			@echo "\033[32;01m minilibx [OK]"

$(PRINTF):
			$(MAKE) -C ./lib/printf
			@echo "\033[0;34m printf [OK]"

$(LIBFT):
			$(MAKE) -C ./lib/libft
			@echo "\033[1m libft [OK]"

re: fclean all

clean:
	rm -rf $(OBJ)
	rm -rf $(B_OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BNAME)
	@make clean -C ./lib/minilibx
	@make clean -C ./lib/printf
	@make clean -C ./lib/libft
	rm -rf ./lib/libft/libft.a
	rm -rf ./lib/printf/libftprintf.a

.PHONY: clean fclean re all
