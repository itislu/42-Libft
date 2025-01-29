/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:16:22 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 09:14:14 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strtok function checks if the string s contains digits ONLY.
 *
 * @param s    The string to check.
 *
 * @return     Returns 1 if the string s containts digits only, otherwise 0.
 *
 */
int	ft_strisdigits(const char *s)
{
	const unsigned char	*casted_ptr_s;

	if (s == NULL)
		return (0);
	casted_ptr_s = (const unsigned char *) s;
	while (ft_isdigit(*casted_ptr_s))
		casted_ptr_s++;
	if (*casted_ptr_s == '\0')
		return (1);
	return (0);
}
