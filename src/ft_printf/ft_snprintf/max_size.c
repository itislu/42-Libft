/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:20:35 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 09:58:36 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

size_t	max_size(t_sformat *f, size_t size)
{
	size_t	max_size;

	if (f->sprinted + size <= f->size)
		max_size = size;
	else
		max_size = f->size - f->sprinted;
	return (max_size);
}
