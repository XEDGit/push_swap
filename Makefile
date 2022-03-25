SRC := push_swap.c stack_algorythms.c list.c std_stack.c arguments.c libft/libft.a
FLAGS := -g -Wall -Wextra -Werror

push_swap: $(SRC)
	@echo "\nCompiling library..."
	@make lib
	@echo "\nCompiling executable..."
	$(CC) $(FLAGS) $(SRC) -o push_swap
	@echo "\nDone!"
d: $(SRC)
	$(CC) -fsanitize=address -g3 $(FLAGS) $(SRC) -o push_swap
lib:
	@cd libft && make
clean:
	rm -f push_swap
re:
	@make clean
	@echo "\nRecompiling library..."
	@cd libft && make re
	@echo "\nRecompiling executable..."
	$(CC) $(FLAGS) $(SRC) -o push_swap
	@echo "\nDone!"