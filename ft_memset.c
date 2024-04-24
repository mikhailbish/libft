/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:31:30 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/04/23 17:47:11 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*res_ptr;

	res_ptr = (unsigned char *)b;
	while (len--)
	{
		*res_ptr = (unsigned char)c;
		res_ptr++;
	}
	return (b);
}
