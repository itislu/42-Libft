/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:17:16 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 15:23:26 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>
#include <limits.h>

int	return_value(t_sformat *f)
{
	if (f->sprinted > INT_MAX)
	{
		errno = EOVERFLOW;
		return (-1);
	}
	return ((int)f->sprinted);
}
