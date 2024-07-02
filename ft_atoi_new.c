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
				return (-1);
		}
		str++;
	}
	if (sign > 0)
	{
		old = num;
		num = -num;
		if (old == num )
			return (0);
	}
	return ((int)num);
}

#include <stdio.h>
int main(void)
{
	char numnum[] = "0000000000";
	int i = 0;
	int k = 0;
	int z = 0;
	printf("asd%d %d\n", k, z);
	char *somnum  = (char *)numnum;
	while(*somnum)
	{
		i = 0;
		while (i < 10)
		{
			*somnum = (char)i + '0';
			k = ft_atoi(somnum);
			z = atoi(somnum);
			if (k!=z)
				printf("%d %d\n", k, z);
			i++;
		}
		somnum++;
	}
	printf("done\n");
}
