/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:08:17 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 12:45:22 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*casted_ptr_s1;
	const unsigned char	*casted_ptr_s2;
	size_t				i;

	casted_ptr_s1 = (const unsigned char *)s1;
	casted_ptr_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (casted_ptr_s1[i] != casted_ptr_s2[i])
			return ((int)casted_ptr_s1[i] - casted_ptr_s2[i]);
		i++;
	}
	return (0);
}
