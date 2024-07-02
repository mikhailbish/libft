#include "libft.h"
#include <stdlib.h>
int	ft_atoi(const char *str)
{
//check spaces
//check signs
//check dig
	long num;
	long old;
	long sign;
	
	num = 0;
	sign  = 1;
	while(ft_isdigit(*str))
	{
		old = num;
		num -= (long)((*str) - '0');
		if (ft_isdigit(*(str + 1)))
			num *= 10;
		if (num > old)
		{
			if (sign < 0)
				return (0);
		}
		str++;
	}
	if (sign > 0)
	{
		old = num;
		num = -num;
		if (old == num )
			return (-1);
	}
	return ((int)num);
}

#include <stdio.h>
int main(void)
{
	char numnum[] = ""
	int k = ft_atoi("1223");
	int z = atoi("1223");
	printf("%d\n%d\n", k,z);
}
