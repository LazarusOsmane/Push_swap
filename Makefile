SRC = sort_utils.c stack.c mediane.c rules.c check.c main.c sort.c
OBJ = ${SRC:.c=.o}
CFLAG = -g3 -Wall -Werror -Wextra
SFLAG = -g3 -Wall -Werror -Wextra -fsanitize=address 
CC = gcc
LIBFT = ./libft/libft.a

all: push_swap

push_swap: $(OBJ)
	$(CC) $(CFLAG) $^ $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAG) -c $^ 

clean: 
	rm *.o

fclean:
	rm *.o push_swap;

re: fclean all

.PHONY:  all clean fclean re
