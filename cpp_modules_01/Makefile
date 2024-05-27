NAME = replace
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CPP = g++

all : $(NAME)
	
$(NAME) : $(OBJ)
	@$(CPP) $(FLAGS)  -o $(NAME) $(OBJ)

fclean : clean
	@rm -rf $(NAME)
clean :
	@rm -rf $(OBJ)

re : fclean all

.PHONY: all clean fclean re
