SRC := ./src/push_swap.c ./src/stack_algorythms.c ./src/list.c ./src/std_stack.c ./src/arguments.c ./libft/libft.a ./src/small_stack_algorythms.c
FLAGS := -Wall -Wextra -Werror -Iincludes -Ilibft
NAME := push_swap
LIB := libft/libft.a

$(NAME): $(SRC)
	@echo "\nCompiling executable..."
	gcc $(FLAGS) $(SRC) -o $(NAME)
	@echo "\nDone!"

all:
	@make

$(LIB):
	@echo "\nCompiling library archive..."
	@make -C ./libft

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)
	@make fclean -C ./libft

re: fclean $(LIB) $(NAME)
