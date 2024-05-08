/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:49:10 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/05/08 21:29:25 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*skip_spaces(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
	{
		str++;
	}
	return (str);
}

static int	ft_numlen(const char *num_str)
{
	const char	*tmp;

	tmp = num_str;
	while (ft_isdigit(*tmp))
		tmp++;
	return (tmp - num_str);
}

static int	ft_overflow_handler(const char *num_str, int sign)
{
	char	*max_long;
	char	*min_long;
	int		max_length;
	int		comparison_result;
	int		n_length;

	while (*num_str == '0')
		num_str++;
	n_length = ft_numlen(num_str);
	max_long = "9223372036854775807";
	min_long = "9223372036854775808";
	max_length = ft_strlen(max_long);
	comparison_result = -1;
	if (ft_numlen(num_str) == ft_numlen(max_long) && sign == 1)
		comparison_result = ft_strncmp(num_str, max_long, n_length);
	else if (ft_numlen(num_str) == ft_numlen(max_long) && sign == -1)
		comparison_result = ft_strncmp(num_str, min_long, n_length);
	if (ft_numlen(num_str) > ft_numlen(max_long))
		comparison_result = 1;
	if (comparison_result > 0 && sign > 0)
		return (-1);
	if (comparison_result > 0 && sign < 0)
		return (0);
	return (1);
}

static int	calc_num(const char *str, int sign)
{
	int	number;

	number = 0;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (sign * number);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	of_result;

	sign = 1;
	str = skip_spaces((char *)str);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	of_result = ft_overflow_handler(str, sign);
	if (of_result == 0 || of_result == -1)
		return (of_result);
	return (calc_num(str, sign));
}
