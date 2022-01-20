SRC = ft_stack.c ft_rules.c ft_algo.c  main.c
OBJ = ${SRC:.c=.o}
CFLAG = -g3 -Wall -Werror -Wextra
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
	rm *.o;
	rm push_swap;

re: fclean all

.PHONY:  all clean fclean re
