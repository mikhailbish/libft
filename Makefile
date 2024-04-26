NAME=libft.a
#.PHONY: all clean
FUNCTIONS=ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_strchr \
		ft_strdup \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \


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

$(NAME): $(O_FILES) libft.h
	ar rcs $(NAME) $(O_FILES)

$(O_FILES): $(C_FILES)
	cc -c $^

clean:
	rm $(O_FILES)
	rm $(NAME)
cleant:
	rm test/test
	rm test/libft.a
	rm test/libft.h
