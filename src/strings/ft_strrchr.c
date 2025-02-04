/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:16:32 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/04 22:01:28 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	casted_c = (char)c;
	const char	*last;

	if (casted_c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	last = NULL;
	while (*s)
	{
		if (*s == casted_c)
			last = s;
		s++;
	}
	return ((char *)last);
}
