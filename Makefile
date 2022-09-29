SRC := ./src/push_swap.c ./src/stack_algorythms.c ./src/list.c ./src/std_stack.c ./src/arguments.c ./libft/libft.a ./src/small_stack_algorythms.c
FLAGS := -Wall -Wextra -Werror -Iincludes -Ilibft
NAME := push_swap

$(NAME): $(SRC)
	@echo "\nCompiling executable..."
	gcc $(FLAGS) $(SRC) -o $(NAME)
	@echo "\nDone!"
all:
	@make
libft/libft.a:
	@make -C ./libft
clean:
	rm -f $(NAME)
fclean:
	rm -f $(NAME)
	@make fclean -C ./libft
re:
	@make clean
	@echo "\nRecompiling library..."
	@make re -C ./libft
	@echo "\nRecompiling executable..."
	gcc $(FLAGS) $(SRC) -o $(NAME)
	@echo "\nDone!"
