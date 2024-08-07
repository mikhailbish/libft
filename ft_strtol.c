/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:59:48 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/08/07 18:25:43 by mbutuzov         ###   ########.fr       */
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

static char *resolve_endptr(int prefix, int digits, char *start, char *curr)
{
	if (prefix && !digits)
		return (start + 1);
	if (!digits)
		return (start);
	return (curr);
}

static void set_endptr(char **endptr, char *start, int base)
{
	char	*temp;
	int	digits;
	int	prefix;

	if (!endptr)
		return ;
	temp = start;
	digits = 0;
	prefix = 0;
	while (ft_isspace(*temp))
		temp++;
	if (*temp == '-')
		temp++;
	else if (*temp == '+')
		temp++;
	if ((!base || base == 16) && *temp == '0' &&
		(*(temp + 1) == 'x' || *(temp + 1) == 'X'))
	{
		prefix++;
		temp += 2;
	}
	while (ft_ctol_base(*temp, base) != -1)
	{
		digits++;
		temp++;
	}
	*endptr = resolve_endptr(prefix, digits, start, temp);
}

// TODO: update endptr on  overflow and when there are some spaces and signs at the start
// TODO: check base
// TODO: test 
// TODO: debug
// TODO: norm
// TODO: norm
/*
	test res:
	if char is outside base - update endptr
	if overflow, don't stop updating endptr
*/
static long	ft_getnum(const char *str, long sign, int base, char **endptr)
{
	long	num;
	long	tmp;

	num = 0;
	while (ft_ctol_base(*str, base) != -1)
	{
		tmp = num;
		num += (long)(ft_ctol_base(*str, base) * sign);
		if (ft_ctol_base(*(str + 1), base) != -1)
			num *= base;
		if (sign > 0 && num < tmp)
			return (LONG_MAX);
		if (sign < 0 && num > tmp)
			return (LONG_MIN);
		str++;
	}
	return ((long)num);
}

long ft_strtol(const char *nptr, char **endptr, int base)
{
	long long	sign;
	char		*tmp;

	tmp = (char *)nptr;
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
	if ((!base || base == 16) && *nptr == '0' && (*(nptr + 1) == 'x' || *(nptr + 1) == 'X'))
	{
		base = 16;
		nptr += 2;
	}
	else if (!base && *nptr == '0')
		base = 8;
	else if (!base)
		base = 10;
	set_endptr(endptr, tmp, base);
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
	int i = 0;
	char *some[] = {
		"12312",
		"-123123",
		"-",
		"-0x123321",
		"-0x123321",
		"9223372036854775899",
		"922337203685477589",
		"-9223372036854775899",
		"-922337203685477589",
		"--9223372036854775899",
		"--922337203685477589",
		"92233720FFFFFFFFFF",
		"ZXCVBNMawdasd",
		"0xZXCVBNMawdasd",
		"0xZXCVBNMa12wdasd",
		"\0"
	};
	
	char *my_endptr;
	char *sys_endptr;
	char *num = "-1";
	long my_long;
	long sys_long;
	int base;
//	sys_long = strtol(num, &sys_endptr, 0);
//	my_long = ft_strtol(num, &my_endptr, 0);
//	sys_long = strtol(num, &sys_endptr, 0);
//	my_long = ft_strtol(num, &my_endptr, 0);
	while (*some[i])
	{
		base = 0;
		sys_long = strtol(some[i], &sys_endptr, base);
		my_long = ft_strtol(some[i], &my_endptr, base);
		if ((my_long != sys_long) || (my_endptr != sys_endptr))
		{
			printf("string: %s\n", some[i]);
			printf("base:%d\n", base);
			printf("my long: %li\n", my_long);
			printf("syslong: %li\n", sys_long);
			printf("start ptr: %p\n", num);
			printf("my ptr:%p\n", my_endptr);
			printf("sysptr:%p\n", sys_endptr);
			write(1, "\n", 1);
		}
		base = 2;
		while (base < 37)
		{
			sys_long = strtol(some[i], &sys_endptr, base);
			my_long = ft_strtol(some[i], &my_endptr, base);
			if ((my_long != sys_long) || (my_endptr != sys_endptr))
			{
				printf("string: %s\n", some[i]);
				printf("base:%d\n", base);
				printf("my long: %li\n", my_long);
				printf("syslong: %li\n", sys_long);
				printf("start ptr: %p\n", num);
				printf("my ptr:%p\n", my_endptr);
				printf("sysptr:%p\n", sys_endptr);
				write(1, "\n", 1);
			}
			base++;
		}
		i++;
	}
	return (0);
}
