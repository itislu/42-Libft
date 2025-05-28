/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:15:57 by ldulling          #+#    #+#             */
/*   Updated: 2025/03/07 04:14:45 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <sys/param.h>

/**
 * The ft_strlcpy function copies the NUL-terminated string from src to dst.
 * It will copy at most size - 1 characters.
 * It will then NUL-terminate the result, unless size is 0.
 *
 * @param dst     The string to copy to.
 * @param src     The string to copy from.
 * @param size    The total size of dst, including the space for the
 *                NUL-terminator.
 *
 * @return        The total length of src.
 *                If the return value is >= size, the output string has been
 *                truncated.
 *
 * @note          Calling ft_strlcpy with dst equal to NULL with a size not 0,
 *                or with src equal to NULL, is undefined behavior (mirrors the 
 *                behavior of the original strlcpy).
 *                If the src and dst strings overlap, the behavior is undefined.
 */
size_t	ft_strlcpy(char *const dst, const char *const src, const size_t size) // This was a talk with Gabriel, we think it would be correct, but we both think it's also ugly
{
	const size_t	srclen = ft_strlen(src);
	const size_t	cpylen = MIN(srclen, size - 1);

	if (size == 0)
		return (srclen);
	ft_memcpy(dst, src, cpylen);
	dst[cpylen] = '\0';
	return (ft_strlen(src));
}
