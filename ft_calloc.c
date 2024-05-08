/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:20:30 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/05/08 21:29:16 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	l;

	l = 0;
	l--;
	l /= size;
	printf("%lu\n", size);
	if (l < count)
		return (0);
	size_t res = count * size;
	ptr = malloc(res);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
