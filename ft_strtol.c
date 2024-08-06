/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:59:48 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/08/06 22:44:08 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
static maybe_update_end_ptr(size_t)
{

}
*/

// TODO: update endptr on  overflow
// TODO: test 
// TODO: debug
// TODO: norm
static long	ft_getnum(const char *str, long long sign, int base, char **endptr)
{
	long long	num;
	long long	tmp;
	size_t digits;

	digits = 0;
	num = 0;
	while (ft_ctol_base(*str, base) != -1)
	{
		tmp = num;
		num += (long long)(ft_ctol_base(*str, base) * sign);
		if (ft_ctol_base(*(str + 1), base) != -1)
			num *= base;
		if (sign > 0 && num < tmp)
			return (LONG_MAX);
		if (sign < 0 && num > tmp)
			return (LONG_MIN);
		str++;
		digits++;
	}
	write(1, "updated\n", 8);
	
	if (digits && endptr)
	{
		*endptr = (char *)str;
	}
	return ((long)num);
}
/*
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
}
*/
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

long ft_strtol(const char *nptr, char **endptr, int base)
{
	long long	sign;
	char		*str;

	if (endptr)
		*endptr = (char *)nptr;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -sign;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	if (!base && *nptr == '0' && (*(nptr + 1) == 'x' || (*nptr + 1) == 'X'))
	{
		base = 16;
		nptr += 2;
	}
	else if (!base && *nptr == '0')
		base = 8;
	else if (!base)
		base = 10;
	return (ft_getnum(nptr, sign, base, endptr));
}

#include <stdio.h>
int main()
{
/*
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
*/
	char *my_endptr;
	char *sys_endptr;
	char *num = "9223372036854775808";
	long my_long;
	long sys_long;
//	sys_long = strtol(num, &sys_endptr, 0);
//	my_long = ft_strtol(num, &my_endptr, 0);
//	sys_long = strtol(num, &sys_endptr, 0);
//	my_long = ft_strtol(num, &my_endptr, 0);
	sys_long = strtol(num, &sys_endptr, 0);
	my_long = ft_strtol(num, &my_endptr, 0);
	printf("my long: %li\n", my_long);
	printf("syslong: %li\n", sys_long);
	printf("start ptr: %p\n", num);
	printf("my ptr:%p\n", my_endptr);
	printf("sysptr:%p\n", sys_endptr);
	return (0);
}
