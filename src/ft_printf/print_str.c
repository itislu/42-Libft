/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:27:17 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/30 07:05:32 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stddef.h>

static size_t	print(const char *str, size_t len, t_format *f);

size_t	print_str(const char *str, t_format *f)
{
	size_t	len;
	size_t	printed;

	printed = 0;
	if (!str)
	{
		len = ft_strlen(NULL_PRINTOUT_STR);
		if (f->precision >= 0 && len > (size_t)f->precision)
			len = 0;
		printed += print(NULL_PRINTOUT_STR, len, f);
	}
	else
	{
		len = ft_strlen(str);
		if (f->precision >= 0 && len > (size_t)f->precision)
			len = f->precision;
		printed += print(str, len, f);
	}
	return (printed);
}

static size_t	print(const char *str, size_t len, t_format *f)
{
	size_t	printed;

	printed = 0;
	if (!f->minus && f->width > len)
		printed += ft_putnchar_fd(' ', f->width - len, f->fd);
	printed += ft_putnstr_fd(str, len, f->fd);
	if (f->minus && f->width > len)
		printed += ft_putnchar_fd(' ', f->width - len, f->fd);
	return (printed);
}
