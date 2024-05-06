/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:29:32 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/05/06 14:12:00 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const *get_next_del(char const *s, char c)
{
	while(*s != c && *s)
		s++;
	if (*s)
		return (s);
	return (0);
}

static char const *get_next_word_start(char const *s, char c)
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


static int fill_array(char **result, char const *s, char c)
{
	char const	*nd;
	char const	*nw;
	int	counter;
	
	counter = 0;
	nd = s;
	while(nd)
	{
		nw = get_next_word_start(nd, c);
		nd = get_next_del(nw, c);
		if (nd - nw > 0)
			result[counter] = ft_substr(s, nw - s, nd - nw);
		else if (ft_strlen(nw)) 
			result[counter] = ft_substr(s, nw - s, ft_strlen(nw));
		if (!result[counter] && ft_strlen(nw))
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

char **ft_split(char const *s, char c)
{
	char **result;
	int count;

	count = count_words((char *)s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (0);
	if (fill_array(result, s, c))
		return (result);
	return (0);
}
