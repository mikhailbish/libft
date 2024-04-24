#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int get_word_length(const char * s, char c)
{
	int	counter;

	counter = 0;
	while(*s && *s != c)
	{
		counter++;
	}
	return (counter);
}
/*
char *find_next_word(const char *s, char c)
{
	if (!*(s+1))
		return (0);
	s++;
	while (*s && *s != c)
		s = ft_strchr(s, c);
	if (*s)
		return (s);
	return (0);
}*/
// couple of mallocs and done!
char	**ft_split(char const *s, char c)
{
	int counter = 0;
	int length;
	const char* ws;

	ws = s
	length = -1;
	while (length)
	{
		length = get_word_length(ws);
		ws += length;
		counter++;
	}
	
}
