#include "libft.h"
#include <stdio.h>

int main()
{
	char *s = "hello!zzzzzzzz";
	/*
	char **res = ft_split(s, '');
	while (*res)
	{
		printf("%s\n", *res);
		res++;
	}*/
	char **ss = ft_split(s, 'z');
	while (*ss)
	{
		printf("%s\n", *ss);
		ss++;
	}
}
