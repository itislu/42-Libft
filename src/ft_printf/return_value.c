/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:17:16 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/04 17:40:29 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <stddef.h>

int	return_value(size_t printed)
{
	if (printed == (size_t)-1)
	{
		errno = EINVAL;
		return (-1);
	}
	if (printed > INT_MAX)
	{
		errno = EOVERFLOW;
		return (-1);
	}
	return ((int)printed);
}
