/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:30:19 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/04/21 21:33:19 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	counter;
	char	*str_s1;
	char	*str_s2;

	counter = 0;
	str_s1 = (char *)s1;
	str_s2 = (char *)s2;
	while (counter < n)
	{
		if (str_s1[counter] != str_s2[counter])
			return (str_s1[counter] - str_s2[counter]);
		counter++;
	}
	return (0);
}
