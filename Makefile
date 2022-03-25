SRC := push_swap.c stack_algorythms.c list.c std_stack.c arguments.c libft/libft.a
FLAGS := -Wall -Wextra -Werror

push_swap: $(SRC)
	@echo "\nCompiling executable..."
	gcc $(FLAGS) $(SRC) -o push_swap
	@echo "\nDone!"
all:
	@make
libft/libft.a:
	@cd libft && make
clean:
	rm -f push_swap
fclean:
	rm -f push_swap
	@cd libft && make fclean
re:
	@make clean
	@echo "\nRecompiling library..."
	@cd libft && make re
	@echo "\nRecompiling executable..."
	gcc $(FLAGS) $(SRC) -o push_swap
	@echo "\nDone!"