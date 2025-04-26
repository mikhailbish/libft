// realloc
/*
void *ft_realloc(void *ptr, size_t size)
{
	malloc(size)
	free(ptr)
}
*/
#include "libft.h"

typedef struct s_memory_node
{
	void	*ptr;
	size_t	size;
}	t_memory_node;

int free_many(void **ptrs)
{
	while (*ptrs)
	{
		free(*ptrs)
		*ptrs = 0;
		ptrs++;
	}
	return (1);
}

# define FT_GNMN_MALLOC_COUNT 2

void *spec_malloc(void **ptrs, size_t size)
{
	int	i;

	i = 0;
	while (ptrs[i])
		i++;
	ptrs[i] = malloc(size);
	if (!ptrs[i] && free_many(ptrs))
		return (0);
	return (ptrs[i]);
}

t_memory_node *get_new_memory_node(size_t size)
{
	t_memory_node	*ptr;
	void *to_free[FT_GNMN_MALLOC_COUNT + 1];

	ft_bzero(to_free, (FT_GNMN_MALLOC_COUNT + 1) * sizeof(void *));
	ptr = spec_malloc(to_free, sizeof(t_memory_node));
	if (!ptr)
		return (0);
	ptr->ptr = spec_malloc(to_free, size);
	if (!ptr->ptr)
		return (0);
	ptr->size = size;
	return (ptr);
}

void free_memory_node(t_memory_node **ptr)
{
	if (!*ptr)
		return;
	free(*ptr->ptr);
	free(*ptr);
	*ptr = 0;
}

t_memory_node *create_new_node_lstadd_back(t_list **lst, size_t size)
{
	t_memory_node	*node;
	t_list		*item;

	node = get_new_memory_node(size);
	if (!node)
		return (0);
	item = ft_lstnew(node);
	if (!item)
	{
		free_memory_node(&node);
		return (0);
	}
	ft_lstadd_back(lst, item);
	return (node);
}

int masd()
{
	return (12);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t size)
{
	void	*new_ptr;

	if (!ptr)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size + 1);
	if (!new_ptr)
		return (NULL);
	if (old_size > size)
		ft_memcpy(new_ptr, ptr, size);
	else
		ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

int main()
{
	void *ptr1;
	void *ptr2;

//	ptr1 = malloc(10);
//	ptr2 = ft_realloc(ptr1, 10, 30);
	ptr2 = ft_realloc(malloc(30), 30, 10);
	free(ptr2);
	return (0);
}

