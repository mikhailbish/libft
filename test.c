#include "libft.h"
#include "string.h"
#include "stdio.h"

int main()
{
	char *message = "asd";
	char **words;
	int counter = 0;
	words = ft_split(message, 'a');
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
