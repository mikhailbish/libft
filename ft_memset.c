/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:17:57 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/07/05 17:42:28 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*put_ul(size_t len, void *ptr, unsigned long long num)
{
	unsigned long long	*chunk;

	chunk = (unsigned long long *)ptr;
	while (len >= sizeof(unsigned long long))
	{
		*chunk = num;
		chunk++;
		len -= sizeof(unsigned long long);
	}
	return ((void *)chunk);
}

void	*ft_memset(void *mem, int c, size_t len)
{
	unsigned long long	*chunk;
	unsigned long long	tmp;
	unsigned char		*str;
	int					chunk_size;

	tmp = 0;
	chunk = (unsigned long long *)mem;
	chunk_size = (int) sizeof(unsigned long long);
	while (chunk_size > 0)
	{
		tmp += (unsigned long long)(unsigned char)c;
		if (chunk_size > 1)
			tmp = tmp << 8;
		chunk_size--;
	}
/*	if (len >= sizeof(unsigned long long))
//		chunk = (unsigned long long *)put_ul(len, mem, tmp);
	len = len - ((void *)chunk - mem);
	str = (unsigned char *)chunk;
	while (len--)
	{
		*str = (unsigned char)c;
		str++;
	}*/
	return (mem);
}
