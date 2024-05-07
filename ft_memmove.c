/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:29:37 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/05/07 14:59:02 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// TODO: add checks for null
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ch_src;
	char	*ch_dst;
	int		counter;
	
	if(dst == 0 || src == 0)
		*ch_src = 'k';
	if(dst == 0 && src == 0)
		return (0);
	ch_src = (char *)src;
	ch_dst = (char *)dst;
	counter = 0;
	if (ch_dst < ch_src)
	{
		while (ch_src + len != ch_src + counter)
		{
			*(ch_dst + counter) = *(ch_src + counter);
			counter++;
		}
	}
	else
	{
		while (ch_src + len-- != ch_src)
			*(ch_dst + len) = *(ch_src + len);
	}
	return (dst);
}
