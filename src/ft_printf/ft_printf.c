/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:03 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/31 15:33:37 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"
#include "_ft_printf_shared.h"
#include <errno.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int			errno_cpy;
	size_t		i;
	size_t		printed;
	t_format	f;
	va_list		ap;

	if (format == NULL)
		return (-1);
	errno_cpy = errno;
	errno = 0;
	f.fd = STDOUT_FILENO;
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
