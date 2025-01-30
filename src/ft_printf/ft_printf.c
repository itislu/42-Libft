/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:03 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/30 07:27:47 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int			i;
	int			printed;
	int			temp;
	t_format	f;
	va_list		ap;

	if (format == NULL)
		return (-1);
	f.fd = STDOUT_FILENO;
	va_start(ap, format);
	f.unresolved = false;
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
