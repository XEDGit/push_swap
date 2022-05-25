SRC := push_swap.c stack_algorythms.c list.c std_stack.c arguments.c libft/libft.a small_stack_algorythms.c
FLAGS := -Wall -Wextra -Werror

push_swap: $(SRC)
	@echo "\nCompiling executable..."
	gcc $(FLAGS) $(SRC) -o push_swap
	@echo "\nDone!"
all:
	@make
libft/libft.a:
	@make -C ./libft
clean:
	rm -f push_swap
fclean:
	rm -f push_swap
	@make fclean -C ./libft
re:
	@make clean
	@echo "\nRecompiling library..."
	@make re -C ./libft
	@echo "\nRecompiling executable..."
	gcc $(FLAGS) $(SRC) -o push_swap
	@echo "\nDone!"
