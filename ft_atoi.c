#include "libft.h"

static int ft_getnum(const char *str, long long sign)
{
	long long num;
	long long tmp;
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
	long long num;
	long long old;
	long long sign;
	
	sign  = 1;
	while (*str == '\f' || *str == '\n' || *str == '\r' || *str == '\t' || *str == '\v' || *str == ' ')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -sign;
		str++;
	} else if (*str == '+')
		str++;
	return (ft_getnum(str, sign));
}
