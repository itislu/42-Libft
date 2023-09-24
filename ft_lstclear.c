/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:04:22 by ldulling          #+#    #+#             */
/*   Updated: 2023/09/24 16:23:59 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Caution: frees the list without deleting the content if del is NULL */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;

	if (del != NULL)
	{
		while (*lst != NULL)
		{
			cur = *lst;
			*lst = (*lst)-> next;
			(*del)(cur -> content);
			free(cur);
		}
	}
	else
	{
		while (*lst != NULL)
		{
			cur = *lst;
			*lst = (*lst)-> next;
			free(cur);
		}
	}
	return ;
}
