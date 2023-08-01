NAME = client
NAME1 = server
SRC = ./client.c
SRC1 = ./server.c
OBJ = $(SRC:.=.o)
OBJ1 = $(SRC1:.=.o)
CC = gcc

all : $(NAME) $(NAME1)
	$(CC)  $(OBJ) -o $(NAME)
	$(CC)  $(OBJ1) -o $(NAME1)

re : fclean all

clean :
	rm -rf *.o
fclean : clean
	rm -rf $(NAME) $(NAME1)
	rm -rf a.out

.PHONY = re fclean clean