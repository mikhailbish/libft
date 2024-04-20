/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:10:35 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/04/20 18:28:34 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *alt;
	char character;

	alt = (char *)s;
	character = (char)c;
	while(*alt && n--)
	{
		if (*alt == character)
			return alt;
		alt++;
	}
	return (0);
}
