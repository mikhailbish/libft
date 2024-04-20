/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:57:33 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/04/20 14:26:29 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		counter;
	char	*ch_src;
	char	*ch_dst;


	counter = 0;
	ch_src = (char *)src;
	ch_dst = (char *)dst;
	while (n - counter)
	{
		ch_dst[counter] = ch_src[counter];
		counter++;
	}

	return (dst);
}
