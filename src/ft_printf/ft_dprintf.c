/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:03 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/04 17:34:10 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"
#include "_ft_printf_shared.h"
#include <errno.h>
#include <stdarg.h>
#include <stddef.h>

int	ft_dprintf(int fd, const char *format, ...)
{
	int			errno_cpy;
	size_t		i;
	size_t		printed;
	t_format	f;
	va_list		ap;

	if (format == NULL)
		return (return_value(-1));
	errno_cpy = errno;
	errno = 0;
	f.fd = fd;
	f.unresolved = false;
	printed = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] && errno == 0)
	{
		reset_format(&f);
		printed += parseandprint(format, &i, &f, &ap);
	}
	va_end(ap);
	if (errno != 0)
		return (-1);
	errno = errno_cpy;
	return (return_value(printed));
}
