/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:08:06 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 10:10:14 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*cur;

	n = 0;
	cur = lst;
	while (cur != NULL)
	{
		n++;
		cur = cur->next;
	}
	return (n);
}
