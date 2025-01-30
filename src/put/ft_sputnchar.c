/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sputnchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 02:17:12 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 17:42:00 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_sputnchar(char *str, unsigned char c, size_t n)
{
	size_t	written;

	if (str == NULL)
		return (0);
	written = 0;
	while (written < n)
	{
		ft_memcpy(&str[written], &c, 1);
		written++;
	}
	return (written);
}
