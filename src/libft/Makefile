SOURCES :=	ft_isalpha.c \
			ft_abs.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strlen.c \
			ft_atoi.c \
			ft_isspace.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_bzero.c \
			ft_strdup.c \
			ft_memset.c \
			ft_memmove.c \
			ft_memcpy.c \
			ft_calloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strlcpy.c \
			ft_strplen.c \
			ft_strclen.c \
			ft_strlcat.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_itoa.c \
			ft_strrev.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split.c \
			ft_strmapi.c \
			ft_striteri.c			

BONUS_SOURCES := 	ft_lstadd_back_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstnew_bonus.c \
					ft_lstmap_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstlast_bonus.c
		
OUTS := $(SOURCES:.c=.o)

BONUS_OUTS := $(BONUS_SOURCES:.c=.o)

NAME := libft.a

$(NAME): $(OUTS) $(BONUS_OUTS)
	ar cr $(NAME) $(OUTS) $(BONUS_OUTS)

$(OUTS): $(SOURCES)

$(BONUS_OUTS): $(BONUS_SOURCES)

clean:
	rm -f $(OUTS)
fclean:
	rm -f $(NAME) && make fullclean
oclean:
	rm -f $(OUTS)
bclean:
	rm -f $(BONUS_OUTS)
fullclean:
	make oclean && make bclean
lib:
	make all && make oclean
re:
	make fclean && make
bonus: $(BONUS_SOURCES)
	gcc -c -Wall -Wextra -Werror $(BONUS_SOURCES) && ar q $(NAME) 