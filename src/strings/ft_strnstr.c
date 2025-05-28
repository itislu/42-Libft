/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:16:27 by ldulling          #+#    #+#             */
/*   Updated: 2025/03/07 01:22:22 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

/**
 * The ft_strnstr function locates the first occurrence of the NUL-terminated
 * string little in the string big, where not more than len characters are
 * searched.
 *
 * @param big       The string to be scanned.
 * @param little    The string to be searched within big.
 * @param len       The number of characters to be scanned in big.
 *
 * @return          If little is an empty string, big is returned; if little
 *                  occurs nowhere in big, NULL is returned; otherwise a pointer
 *                  to the first character of the first occurrence of little is
 *                  returned.
 *
 * @note            Calling ft_strnstr with big or little equal to NULL is
 *                  undefined behavior (mirrors the behavior of the original
 *                  strnstr).
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	while (true)
	{
		l = 0;
		while (b + l < len && little[l] == big[b + l] && little[l] != '\0')
			l++;
		if (little[l] == '\0')
			return ((char *)&big[b]);
		if (b + l == len || big[b + l] == '\0')
			return (NULL);
		b++;
	}
}
