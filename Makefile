SRC = sort_utils.c stack.c mediane.c rules.c check.c main.c sort.c
OBJ = ${SRC:.c=.o}
SRC_BONUS = checker.c checker_utils.c rules.c mediane.c stack.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CFLAG = -g3 -Wall -Werror -Wextra
SFLAG = -g3 -Wall -Werror -Wextra -fsanitize=address 
CC = gcc
LIBFT = ./libft/libft.a

all: push_swap

push_swap: $(OBJ)
	$(CC) $(CFLAG) $^ $(LIBFT) -o $@

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAG) $^ $(LIBFT) -o checker

$(OBJ_BONUS): $(SRC_BONUS)
	$(CC) $(CFLAG) -c $^ 

%.o: %.c
	$(CC) $(CFLAG) -c $^ 


clean: 
	rm *.o

fclean:
	rm *.o push_swap;

re: fclean all

.PHONY:  all clean fclean re bonus
