/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:49:10 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/04/20 20:41:04 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*skip_spaces(char *str)
{
	while(*str == 't' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
	{
		str++;
	}
	return str;
}

int	ft_atoi(const char *str)
{
	int number;
	int sign;
	char *tmp;

	number = 0;
	sign = 1;
	str = skip_spaces((char *)str);
	if (*str == '-')
		sign = -1;
		str++;
	if (*str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	// errno
	// check str length vs check minlong maxlong
	tmp = (char *)str;
	while (ft_isdigit(*tmp))
		tmp++;
	if (tmp - str > 19)
		return (0);
	while (ft_isdigit(*str))
	{
		number = number * 10 +  *str - '0';
		str++;
	}
	return (sign * number);
}
