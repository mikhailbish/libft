#include "libft.h"
#include "string.h"
#include "stdio.h"

int main()
{
	char *message = "^^^1^^2a,^^^^3^^^^--h^^^^";
	char **words;
	int counter = 0;
	words = ft_split(message, '^');
	while (*words)
	{
		printf("%s\n", *words);
		words++;
		counter++;
	}
	words -= counter;
	while (*words)
	{
		free(*words);
		words++;
	}
	words -= counter;
	free(words);
}
