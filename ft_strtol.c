/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:59:48 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/08/06 20:47:01 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static int	ft_getnum(const char *str, long long sign)
{
	long long	num;
	long long	tmp;

	num = 0;
	while (ft_isdigit(*str))
	{
		tmp = num;
		num += (long long)(((*str) - '0') * sign);
		if (ft_isdigit(*(str + 1)))
			num *= 10;
		if (sign > 0 && num < tmp)
			return (-1);
		if (sign < 0 && num > tmp)
			return (0);
		str++;
	}
	return ((int)num);
}
int	ft_atoi(const char *str)
{
	long long	sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	return (ft_getnum(str, sign));
}*/
/*
int	legal_char_base(char digit, int base)
{
	int max_legal_char;

	max_legal_char = '0' + base - 1;
	if (base < 11)
	{
		if (!ft_isdigit(digit) || (digit > max_legal_char))
			return (0);
		else
			return (1);
	}
	max_legal_char = 'A' + base - 11;
	if (!(ft_isdigit(digit) || ft_isupper(digit)) || digit > max_legal_char)
		return (0);
	return (1);
}
*/
/*
long	ctol(char digit, int base)
{
	int max_legal_char;

	max_legal_char = '0' + base - 1;
	if (base < 11)
	{
		if (!ft_isdigit(digit) || (digit > max_legal_char))
			return (-1);
		else
			return (digit - '0');
	}
	max_legal_char = 'A' + base - 11;
	if (!(ft_isdigit(digit) || ft_isupper(digit)) || digit > max_legal_char)
		return (-1);
	return (digit - 'A' + 11);
}*/
long	ft_ctol_base(char digit, int base)
{
	long	num;

	if (!(ft_isdigit(digit) || ft_isupper(digit) || ft_islower(digit)))
		return (-1);
	num = (long)(digit - '0');
	if (base < 11)
	{
		if (num < (long)base)
			return (num);
		else
			return (-1);
	}
	if (ft_isupper(digit))
		num = (long)(digit - 'A' + 10);
	if (ft_islower(digit))
		num = (long)(digit - 'a' + 10);
	if (num < (long)base)
		return (num);
	return (-1);
}
/*
long ft_strtol(const char *nptr, char **endptr, int base)
{
	const char	tmp;

	tmp = nptr;
	if (endptr != 0)
		*endptr = (char *)nptr;
}

#include <stdio.h>
int main()
{

	int max_legal_char;
	int base = 16;
	if (base < 11)
		max_legal_char = '0' + base - 1;
	else
		max_legal_char = 'A' + base - 11;

	ft_printf("%c\n", max_legal_char);
	ft_printf("%d\n", legal_char_base('~', base));
	long val = ft_ctol_base('3', 36);
	long num = strtol("0xFFF", 0, 0);
	printf("%li\n", num);
	return (0);
}*/
