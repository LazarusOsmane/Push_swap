SRC = sort_utils.c stack.c mediane.c rules.c check.c main.c sort.c
OBJ = ${SRC:.c=.o}
SRC_BONUS = checker_bonus.c checker_utils_bonus.c rules.c mediane.c stack.c check.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CFLAG = -g3 -Wall -Werror -Wextra
SFLAG = -g3 -Wall -Werror -Wextra -fsanitize=address 
CC = gcc
LIBFT = ./libft/libft.a

all: push_swap

push_swap: $(OBJ)
	cd libft/ && make
	$(CC) $(CFLAG) $^ $(LIBFT) -o $@

bonus: $(OBJ_BONUS)
	cd libft/ && make
	$(CC) $(CFLAG) $^ $(LIBFT) -o checker

$(OBJ_BONUS): $(SRC_BONUS)
	$(CC) $(CFLAG) -c $^ 

%.o: %.c
	$(CC) $(CFLAG) -c $^ 

clean: 
	cd libft/ && make clean
	rm -f $(OBJ)

fclean: clean
	rm -f push_swap

bonus_clean:
	cd libft/ && make clean
	rm -f $(OBJ_BONUS)

bonus_flcean:
	cd libft/ && make fclean
	rm $(OBJ_BONUS) checker


re: fclean all

.PHONY:  all clean fclean re bonus
