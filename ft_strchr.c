/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:27:46 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/04/20 17:31:22 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *a = (char *)s;
	while(*a)
	{
		if (c == *a)
			return (a);
		a++;
	}
	if (c == *a)
		return (a);
	return (0);
}
