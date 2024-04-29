/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:27:46 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/04/29 21:13:38 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	character;

	character = c;
	while (*s)
	{
		if (character == *s)
			return ((char *)s);
		s++;
	}
	if (character == *s)
		return ((char *)s);
	return (0);
}
