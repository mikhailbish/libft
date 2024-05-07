#include "libft.h"
#include <stdio.h>
#include <string.h>
void	*lstmaptest(void *content)
{
	return ((void *)ft_itoa(ft_strlen((char *)content)));
}
void	del(void *content)
{
	printf("deleted: %s\n", (char *)content);
}
int main()
{
/*
	char *content1 = "asd";
	char *content2 = "wdsaf";

	t_list *o = ft_lstnew(content1);
	t_list *c = ft_lstnew(content2);
	ft_lstadd_front(&o, c);


	int l = ft_lstsize(c);
	char m = l + '0';
	write(1, &m, 1);
	write(1, "\n", 1);

	t_list *some = ft_lstlast(o);
	write(1, (char *)some->content, ft_strlen(some->content));
	
	char *content = "new in the end";
	t_list *new = ft_lstnew(content);
	ft_lstadd_back(&o, new);
	t_list *tmp = c;
	while (tmp->next)
	{
		write(1, c->content, ft_strlen(c->content));
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	write(1, "after map\n", 10);
	c = ft_lstmap(c, lstmaptest, del);
	write(1, c->content, ft_strlen(c->content));
	tmp = c;
	while (tmp->next)
	{
		write(1, c->content, ft_strlen(c->content));
		write(1, "\n", 1);
		tmp = tmp->next;
	}
*/

//	ft_memmove(0, 0, 5);
//	memmove(0, 0, 5);
//	ft_strnstr("asd", "as", -1);
	char haystack[30] = "aaabcabcd";
	char needle[10] = "bcd";
	int i = -5;
	while (i < 10)
	{
		char *a = ft_strnstr(haystack, needle, i);
		char *b = strnstr(haystack, needle, i);
		printf("my:   %s\n", a);
		printf("other:%s\n", b);
		i++;
	}
//	size_t num = 0;
//	num--;
//	printf("%lu", num);
}
