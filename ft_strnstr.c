/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:02:07 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/05/07 20:55:31 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while(*haystack && len--)
	{
		if (ft_strlen(needle) >= len && ft_strlen(haystack) >= len)
		{
			if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0) 
				return ((char *)haystack);
		}
		else
			return 0;
		haystack++;
//		len--;
	}
	return (0);
}
