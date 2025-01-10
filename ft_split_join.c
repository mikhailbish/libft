#include "libft.h"

static size_t	count_tab_chars(char **tab)
{
	size_t	i;
	size_t	char_count;

	char_count = 0;
	i = 0;
	while (tab[i])
		char_count += ft_strlen(tab[i++]);
	return (char_count);
}

//static void ft_cpy_word_move_ptr(word)

// TODO: add to .h
int	ft_count_split(char **texts)
{
	int	i;

	i = 0;
	while (texts[i])
	{
		i++;
	}
	return (i);
}

int write_word(char *text, char *word, size_t char_length)
{
	int length;
	size_t word_length;

	word_length = ft_strlen(word);
	length = word_length;
	if (!length)
		return (0);
	while (word_length--)
		text[--char_length] = word[word_length];
	
	return (length);
}

char	*ft_split_join(char **tab, char *sep)
{
	char	*text;
	char	*word;
	size_t	char_length;
	size_t	word_length;
	size_t	tab_length;

	tab_length = ft_count_split(tab);
	word_length = 0;
	if (sep)
		word_length += ft_strlen(sep);
	char_length = count_tab_chars(tab) + word_length * (tab_length - 1);
//	write(1, "here\n", 5);
	text = ft_calloc(char_length + 1, sizeof (char));
	if (!text)
		return (0);
	while (tab_length--)
	{
		word = tab[tab_length];
/*
		word_length = ft_strlen(word);
		while (word_length--)
			text[--char_length] = word[word_length];
*/
		char_length -= write_word(text, word, char_length);
		if (sep && tab_length)
		{
/*
			word = sep;
			word_length = ft_strlen(word);
			while (word_length--)
				text[--char_length] = word[word_length];
*/
			char_length -= write_word(text, sep, char_length);
		}
	}
	return (text);
}
