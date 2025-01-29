/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:08:06 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 10:09:13 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_lstsize_d(t_list_d *lst)
{
	int			n;
	t_list_d	*cur;

	n = 0;
	cur = lst;
	while (cur != NULL)
	{
		n++;
		cur = cur->next;
	}
	return (n);
}
