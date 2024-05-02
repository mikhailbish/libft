#include "libft.h"
#include "string.h"
#include "stdio.h"

int main()
{
	int l = ft_strncmp("abcdef", "abc\375xx", 5);
	int o = strncmp("abcdef", "abc\375xx", 5);
	printf("%d, %d\n", l, o);
}
