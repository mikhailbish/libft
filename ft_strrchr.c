/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:34:49 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/04/21 21:40:45 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	char	*last_occ;

	a = (char *)s;
	last_occ = 0;
	while (*a)
	{
		if (c == *a)
			last_occ = a;
		a++;
	}
	if (c == *a)
		last_occ = a;
	return (last_occ);
}
