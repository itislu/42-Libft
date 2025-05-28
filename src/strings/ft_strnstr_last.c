/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:05:04 by ldulling          #+#    #+#             */
/*   Updated: 2025/03/06 20:33:40 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/**
 * The ft_strnstr_last function locates the last occurrence of the
 * NUL-terminated string little in the string big, where not more than len
 * characters are searched.
 *
 * @param big       The string to be scanned.
 * @param little    The string to be searched within big.
 * @param len       The number of characters to be scanned in big.
 *
 * @return          If little occurs nowhere in big, NULL is returned;
 *                  otherwise a pointer to the first character of the last
 *                  occurrence of little is returned.
 *
 * @note            Calling ft_strnstr_last with big or little equal to NULL is
 *                  undefined behavior (mirrors the behavior of the original
 *                  basic strnstr).
 */
char	*ft_strnstr_last(const char *big, const char *little, size_t len)
{
	char	*last;
	char	*tmp;

	last = NULL;
	tmp = ft_strnstr(big, little, len);
	while (tmp != NULL)
	{
		last = tmp;
		tmp = ft_strnstr(tmp + 1, little, len - (tmp - big) - 1);
	}
	return (last);
}
