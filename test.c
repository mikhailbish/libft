#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>

char test(unsigned int a, char b)
{
	a -= a;
	return (b + 1);
}
void test1(unsigned int index, char *s)
{
	if (index != 3)
		*s = 'G';
}

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
/*	char **words;

	words = ft_split(message, ' ');
	while (*words)
	{
		printf("%s\n", *words);
		words++;
	}*/
	/*
	char *s = "  I ";
	char c = ' ';
	char **asd = ft_split(s, c);
	while (*asd != 0)
	{
		printf("%s\n", *asd);
		asd++;
	}
	char *m = ft_strmapi("abcd", test);
	write(1, m, ft_strlen(m));*/
	/*
	char ki[20] = "assd asd asd";
	ft_striteri(ki, test1);
*/
/*
	int a = open("test.txt", O_CREAT | O_APPEND | O_WRONLY, 0777 );
	if (a >= 0)
	{
		ft_putchar_fd('k', a);
		ft_putchar_fd('\n', a);
		ft_putstr_fd("asd", a);
		ft_putendl_fd("yo followed by nl", a);
		ft_putstr_fd("asd", a);
	}
*/
/*	
	ft_putnbr_fd(12312300, 1);
	ft_putchar_fd(1, '\n');
	*/
	/*
	char *some = "assd";
	t_list *a = ft_lstnew((void *)some);
	write(1, a->content, 4);
	write(1, "\n", 1);
	char next = (int)a->next + '0';
	write(1, &next, 1);*/

	char *content1 = "asd";
	char *content2 = "wdsaf";

	t_list *o = ft_lstnew(content1);
	t_list *c = ft_lstnew(content2);
	ft_lstadd_front(&o, c);
	/*
	int l = ft_lstsize(c);
	char m = l + '0';
	write(1, &m, 1);
	write(1, "\n", 1);
	*/
//	t_list *some = ft_lstlast(o);
//	write(1, (char *)some->content, ft_strlen(some->content));
	
	char *content = "new in the end";
	t_list *new = ft_lstnew(content);
	ft_lstadd_back(&o, new);
	while (c->next)
	{
		write(1, c->content, ft_strlen(c->content));
		write(1, "\n", 1);
		c = c->next;
	}
	write(1, c->content, ft_strlen(c->content));
	return (0);
}
