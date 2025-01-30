/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:17:16 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 18:17:46 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include <stddef.h>

int	return_value(size_t printed)
{
	if (printed > INT_MAX)
	{
		errno = EOVERFLOW;
		return (-1);
	}
	return ((int)printed);
}
