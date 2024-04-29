/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbutuzov <mbutuzov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:20:04 by mbutuzov          #+#    #+#             */
/*   Updated: 2024/04/28 20:20:15 by mbutuzov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	*current;
	void	*next;

	current = *lst;
	while (current != 0)
	{
		next = current->next;
		ft_delone(current, del);
		current = next;
	}
	*lst = 0;
}
