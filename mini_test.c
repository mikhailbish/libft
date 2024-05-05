#include "libft.h"

static char *get_next_del(char *s, char c)
{
	size_t word_length;
	word_length = ft_strlen(s);
	s = ft_strnstr(s, &c, word_length);
	return (s);
}

static char *get_next_word_start(char *s, char c)
{
	while(*s && *s == c)
		s++;
	return (s);
}

static int count_words(char *s, char c)
{
	char	*nd;
	char	*nw;
	int 	count;

	count = 0;
	nd = s;
	while (nd)
	{
		nw = get_next_word_start(nd, c);
		nd = get_next_del(nw, c);
		count++;
	}
	if (!count)
		count++;
	return (count);
}

static int fill_array(char **result, char *s, char c)
{
	char	*nd;
	char	*nw;
	int	counter;
	
	counter = 0;
	nd = s;
	while(nd)
	{
		nw = get_next_word_start(nd, c);
		nd = get_next_del(nw, c);
		if (nd)
			result[counter] = ft_substr(s, nw - s, nd - nw);
		else 
			result[counter] = ft_substr(s, nw - s, ft_strlen(nw));
		if (!result[counter])
		{
			while(counter--)
				free(result[counter]);
			free(result);
			return (0);
		}
		counter++;
	}
	result[counter] = 0;
	return (counter);
}

char **ft_split(char *s, char c)
{
	char **result;
	int count;

	count = count_words(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (0);
	if (fill_array(result, s, c))
		return (result);
	return (0);
}
