/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:20:35 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/04 18:25:22 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_snprintf.h"
#include <stddef.h>

size_t	max_size(const t_sformat *f, size_t size)
{
	if (f->sprinted + size <= f->size)
		return (size);
	return (f->size - f->sprinted);
}
