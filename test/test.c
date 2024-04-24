#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

const char *find_next_word(const char *s, char c);

int main (void)
{
/*
	void* k = malloc(sizeof(char) * 10);
	ft_memset(k, 97, 7);
	ft_bzero(k, 7);
	int i = 0;
	while (i < 7)
	{
		write(1, k, 1);
		write(1, "\n", 1);
		k++;
		i++;
	}*/
	/*
	
	char k[100] = "wow100";
	char z[100] = "wow";
	void* a = "somete";1000
	
	size_t res = ft_strlcat(k, a, 100);

	printf("%zu\n", res);
	printf("%zu\n", strlcat(z, a, 100));
	printf("%s\n", k);
	printf("%s\n", z);
*/
/*
	char some = ft_toupper('m');
	write(1, &some, 1);
	write(1, "\n", 1);
*/
//	char *l = ft_strchr("asd", 's');
//	char *l = ft_strchr("asd", 'm');
//	char *l = ft_strrchr("asdado", 'd');
//	char *l = ft_strchr("asd", 'd');
/*
	if (l)
		write(1, l, 2);
	else
		write(1, "no", 2);*/
	/*
	char *a = "some";
	char *b = "som";
	int k = ft_strncmp(a, b, 4);
	printf("%d\n", k);
	
	int z = strncmp(a, b, 4);
	printf("%d\n", z);*/
	/*
	void *yoo = "asd";
	void *zoo = "asf";
	int l = ft_memcmp(zoo, yoo, 3);
	printf("%d\n", l);

	int k = memcmp(zoo, yoo, 3);
	printf("%d\n", k);*/
	/*
	char *a = ft_strnstr("long ass message", "", 5);
	char *b = strnstr("long ass message", "", 5);
	printf("%s\n",a);
	printf("%s\n",b);*/
//	printf("%d\n", ft_atoi("-9223372036854775803"));
//	printf("%d\n", 	  atoi("-9223372036854775803"));
//	printf("%lu %ld \n", ULONG_MAX, LONG_MAX);
/*
	char *ptr = (char *)ft_calloc(10, sizeof(char));
	ptr[0] = 'a';
	ptr[1] = 'b';
	printf("%s", ptr);*/
/*	char  *a = ft_strdup("hello there");
	printf("%s", a);
	free(a);*/
	/*
	char *asd = "asdwow";
	char *ye = ft_strtrim(asd, "awos");
	printf("%s", ye);
	*/
/*	char *ups = ft_strjoin("asd", "wow");
	write(1, ups, 6);*/
	

	char *message = " here is my test text";
	printf("%s\n", find_next_word(message, ' '));

/*	char **words;

	words = ft_split(message, ' ');
	while (*words)
	{
		printf("%s\n", *words);
		words++;
	}*/
	
	return (0);
}
	const char *find_next_word(const char *s, char c)
	{
		if (!*(s+1))
			return (0);
		s++;
		while (*s && *s != c)
			s = ft_strchr(s, c);
		if (*(s + 1))
			return (++s);
		return (0);
	}
