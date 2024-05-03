NAME=libft.a
FUNCTIONS=ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_itoa	\
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_split \
			ft_strchr \
			ft_strdup \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_strtrim \
			ft_substr \
			ft_tolower \
			ft_toupper \
			ft_lstadd_back_bonus \
			ft_lstadd_front_bonus \
			ft_lstclear_bonus \
			ft_lstdelone_bonus \
			ft_lstiter_bonus \
			ft_lstlast_bonus \
			ft_lstnew_bonus \
			ft_lstsize_bonus \

all: $(NAME)

# relinking?
test: preptest test/test.c
	cc -o test/test  -Wall -Wextra -Werror test/libft.a test/test.c  && ./test/test
preptest: test/libft.a test/libft.h

test/libft.a: libft.a
	cp libft.a test/

test/libft.h: libft.h
	cp libft.h test/

C_FILES=$(foreach func, $(FUNCTIONS), $(func).c)
O_FILES=$(foreach func, $(FUNCTIONS), $(func).o)
BONUS_C_FILES=$(foreach func, $(BONUS_FUNCTIONS), $(func).c)
BONUS_O_FILES=$(foreach func, $(BONUS_FUNCTIONS), $(func).o)

$(NAME): $(O_FILES)
	ar rcs $(NAME) $(O_FILES)

$(O_FILES): $(C_FILES) libft.h
	cc -c $^

clean:
	rm $(O_FILES)

fclean:
	rm -f $(NAME)

cleant:
	rm test/test
	rm test/libft.a
	rm test/libft.h
