/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:08:23 by ldulling          #+#    #+#             */
/*   Updated: 2025/03/07 00:56:29 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/**
 * The ft_memmove function copies n bytes from memory area src to memory area
 * dest.
 * Unlike ft_memcpy, the memory areas may overlap.
 * This function checks if dest is before or after src in memory, then starts
 * copying from the beginning or the end respectively.
 *
 * @param dest    The memory area to copy to.
 * @param src     The memory area to copy from.
 * @param n       The number of bytes to copy.
 *
 * @return        Returns a pointer to dest.
 *
 * @note          Calling ft_memcpy with dest or src equal to NULL is undefined
 *                behavior (mirrors the behavior of the original memmove).
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*casted_ptr_src = (const unsigned char *)src;
	unsigned char		*casted_ptr_dest;
	size_t				i;

	casted_ptr_dest = (unsigned char *)dest;
	if (casted_ptr_dest <= casted_ptr_src)
	{
		i = 0;
		while (i < n)
		{
			casted_ptr_dest[i] = casted_ptr_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			casted_ptr_dest[i] = casted_ptr_src[i];
	}
	return (dest);
}
