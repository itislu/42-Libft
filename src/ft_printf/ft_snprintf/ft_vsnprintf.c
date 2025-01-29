/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:03 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 12:37:50 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>

int	ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	int			i;
	t_sformat	f;
	va_list		ap_copy;

	if (!check_args(str, size, format, &f))
		return (f.sprinted);
	f.str = str;
	f.size = size - 1;
	va_copy(ap_copy, ap);
	f.unresolved = 0;
	f.sprinted = 0;
	i = 0;
	while (format[i] && f.sprinted < (int)f.size)
	{
		reset_sformat(&f);
		parseandsprint(format, &i, &f, &ap_copy);
		if (f.sprinted == -1)
			break ;
	}
	if (f.sprinted != -1)
		f.str[f.sprinted] = '\0';
	return (va_end(ap_copy), f.sprinted);
}
