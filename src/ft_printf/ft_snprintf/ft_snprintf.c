/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:03 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/10 12:22:12 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_snprintf.h"
#include "../_ft_printf_shared.h"
#include "libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

int	ft_snprintf(char *str, size_t size, const char *format, ...)
{
	size_t		i;
	t_sformat	f;
	va_list		ap;

	if (!check_args(str, size, format, &f))
		return (return_value(f.chars_needed));
	f.str = str;
	f.size = size - 1;
	f.unresolved = false;
	f.sprinted = 0;
	f.chars_needed = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] && f.chars_needed != (size_t)-1)
	{
		reset_sformat(&f);
		parseandsprint(format, &i, &f, &ap);
	}
	va_end(ap);
	f.sprinted = ft_min_u(f.sprinted, SIZE_MAX - 1);
	f.str[f.sprinted] = '\0';
	return (return_value(f.chars_needed));
}
