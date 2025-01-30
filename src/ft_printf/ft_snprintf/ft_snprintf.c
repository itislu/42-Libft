/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:03 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/30 07:29:54 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int			i;
	t_sformat	f;
	va_list		ap;

	if (!check_args(str, size, format, &f))
		return (return_value(&f));
	f.str = str;
	f.size = size - 1;
	va_start(ap, format);
	f.unresolved = false;
	f.sprinted = 0;
	i = 0;
	while (format[i] && f.sprinted < f.size)
	{
		reset_sformat(&f);
		parseandsprint(format, &i, &f, &ap);
		if (f.sprinted == SIZE_MAX)
			break ;
	}
	if (f.sprinted != SIZE_MAX)
		f.str[f.sprinted] = '\0';
	return (va_end(ap), return_value(&f));
}
