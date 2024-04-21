/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:54:35 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/04/21 21:37:29 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total_length;
	size_t	dst_len;
	size_t	counter;

	dst_len = ft_strlen(dst);
	total_length = dst_len + ft_strlen(src);
	dst += dst_len;
	counter = 0;
	while (counter + dst_len < dstsize - 1 && src[counter])
	{
		dst[counter] = src[counter];
		counter++;
	}
	if (dstsize && !(dstsize < dst_len))
		dst[counter] = 0;
	return (total_length);
}
