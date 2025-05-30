/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_merge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:42:36 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/13 02:40:35 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static void		split_list(t_list *head, t_list **front_half, \
							t_list **back_half);
static t_list	*sorted_merge(t_list *front_half, t_list *back_half, \
								const void *(*cmp)(const void *, const void *));

void	ft_lstsort_merge(t_list **lst, \
							const void *(*cmp)(const void *, const void *))
{
	t_list	*front_half;
	t_list	*back_half;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL || cmp == NULL)
		return ;
	split_list(*lst, &front_half, &back_half);
	ft_lstsort_merge(&front_half, cmp);
	ft_lstsort_merge(&back_half, cmp);
	*lst = sorted_merge(front_half, back_half, cmp);
}

static void	split_list(t_list *head, t_list **front_half, t_list **back_half)
{
	t_list	*fast;
	t_list	*slow;

	slow = head;
	fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_half = head;
	*back_half = slow->next;
	slow->next = NULL;
}

static t_list	*sorted_merge(t_list *front_half, t_list *back_half, \
								const void *(*cmp)(const void *, const void *))
{
	t_list	*result;

	if (front_half == NULL)
		return (back_half);
	if (back_half == NULL)
		return (front_half);
	if (cmp(front_half->content, back_half->content) != (void *)0)
	{
		result = front_half;
		result->next = sorted_merge(front_half->next, back_half, cmp);
	}
	else
	{
		result = back_half;
		result->next = sorted_merge(front_half, back_half->next, cmp);
	}
	return (result);
}
