#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

	printf("%d\n", ft_atoi("-922337203685477"));
	printf("%d\n", 	  atoi("-922337203685477"));
	return 0;
}
