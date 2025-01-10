#include "libft.h"


int main(void)
{
	char *str;
	char *arr[] = {
		"text1",
		"text2",
		"more words",
		"hello hello",
		0
	};
//	char *sep = "-|-";
	char *sep = ": ";
/* split_join
	str = ft_split_join((char **)arr, (char *)0);
	if (!str)
		return 1;
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	ft_printf("print done\n");
	free(str);
	str = ft_split_join(arr, "\t");
	if (!str)
		return 1;
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	ft_printf("print done\n");
	free(str);
	str = ft_split_join(arr, sep);
	if (!str)
		return 1;
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	ft_printf("print done\n");
	free(str);
*/
/* va_str_join */
	
/* TODO: add test_cases
	str = va_str_join(4, arr[0], arr[1], arr[2], arr[3]);
	if (!str)
		return 1;
	ft_putstr_fd(str, 1);
	free(str);
	write(1, "\n", 1);
	ft_printf("print done\n");
*/
/* va_str_join_sep */
	
	str = va_str_join_sep(4, sep, arr[0], arr[1], arr[2], arr[3]);
	if (!str)
		return 1;
	ft_putstr_fd(str, 1);
	free(str);
	write(1, "\n", 1);
	ft_printf("print done\n");
	return (0);
}
