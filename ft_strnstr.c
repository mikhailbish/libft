/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:02:07 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/05/06 19:03:04 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	counter;
	int	needle_length;

	if (!*needle)
		return ((char *)haystack);
	needle_length = ft_strlen(needle);
	counter = 0;
	while (*haystack && len--)
	{
		if (*haystack == needle[counter])
		{
			counter++;
			if (counter == needle_length)
				return ((char *)haystack - counter + 1);
		}
		else if (*haystack != needle[counter] && counter != 0)
		{
			counter = 0;
			haystack--;
			len++;
		}
		haystack++;
	}
	return (0);
}
