/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:03 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 09:59:56 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>

int	ft_dprintf(int fd, const char *format, ...)
{
	int			i;
	int			printed;
	int			temp;
	t_format	f;
	va_list		ap;

	if (format == NULL || fd < 0)
		return (-1);
	f.fd = fd;
	va_start(ap, format);
	f.unresolved = 0;
	printed = 0;
	i = 0;
	while (format[i])
	{
		reset_format(&f);
		temp = parseandprint(format, &i, &f, &ap);
		if (temp == -1)
		{
			printed = temp;
			break ;
		}
		printed += temp;
	}
	return (va_end(ap), printed);
}
