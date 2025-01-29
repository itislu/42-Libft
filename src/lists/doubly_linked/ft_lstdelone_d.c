/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:04:26 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/10 16:51:39 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone_d(t_list_d *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (del != NULL && lst->content != NULL)
		(*del)(lst->content);
	free(lst);
	return ;
}
