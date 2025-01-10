#include "libft.h"

// TODO: check va_arg exists?
char	*va_str_join(size_t num, ...)
{
	va_list	list;
	char	**str_list;
	char	*text;
	size_t	i;

	i = 0;
	str_list = ft_calloc(num + 1, sizeof (char *));
	if (!str_list)
		return (0);
	va_start(list, num);
	while (i < num)
		str_list[i++] = va_arg(list, char *);
	va_end(list);
	text = ft_split_join(str_list, 0);
	if (!text)
	{
		free(str_list);
		return (0);
	}
	free(str_list);
	return (text);
}
char	*va_str_join_sep(size_t num, char *sep, ...)
{
	va_list	list;
	char	**str_list;
	char	*text;
	size_t	i;

	i = 0;
	str_list = ft_calloc(num + 1, sizeof (char *));
	if (!str_list)
		return (0);
	va_start(list, sep);
	while (i < num)
		str_list[i++] = va_arg(list, char *);
	va_end(list);
	text = ft_split_join(str_list, sep);
	if (!text)
	{
		free(str_list);
		return (0);
	}
	free(str_list);
	return (text);
}
