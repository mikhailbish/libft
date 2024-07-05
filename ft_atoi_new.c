#include "libft.h"
#include <stdlib.h>
int ft_getnum(const char *str, long long sign)
{
	long long num;
	long long old;

	num = 0;
	while (ft_isdigit(*str))
	{
		old = num;
		num -= (long long)((*str) - '0');
		if (ft_isdigit(*(str + 1)))
			num *= 10;
		if (num > old && sign < 0)
			return (-1);
		str++;
	}
	if (sign > 0)
	{
		old = num;
		num = -num;
		if (old == num)
			return (0);
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
#include <stdio.h>
int main()
{
	printf("\n====================================================\n");
	printf("Test ft_atoi\n");
	printf("====================================================\n");
	printf("%d\n", atoi("18446744073709551616"));
	printf("%d\n", ft_atoi("18446744073709551616"));
	printf("=======================================\n");
	printf("%d\n", atoi("1234"));
	printf("%d\n", ft_atoi("1234"));
	printf("=======================================\n");
	printf("%d\n", atoi("-1234"));
	printf("%d\n", ft_atoi("-1234"));
    printf("=======================================\n");
    printf("%d\n", atoi("12345678901234567890"));
    printf("%d\n", ft_atoi("12345678901234567890"));
    printf("=======================================\n");
    printf("%d\n", atoi("1123456789012345678900000000000"));
    printf("%d\n", ft_atoi("1123456789012345678900000000000"));
    printf("=======================================\n");
    printf("%d\n", atoi("-12345678901234567890"));
    printf("%d\n", ft_atoi("-12345678901234567890"));
    printf("=======================================\n");
    printf("%d\n", atoi("-1123456789012345678900000000000"));
    printf("%d\n", ft_atoi("-1123456789012345678900000000000"));
    printf("=======================================\n");
    printf("%d\n", atoi("2345678901234567890"));
    printf("%d\n", ft_atoi("2345678901234567890"));
    printf("=======================================\n");
    printf("%d\n", atoi("123456789009876543211234567890"));
    printf("%d\n", ft_atoi("123456789009876543211234567890"));
	return (0);
}
