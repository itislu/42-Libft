/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:27:17 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/31 14:27:42 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stddef.h>

static void	sprint(const char *str, size_t len, t_sformat *f);

void	sprint_str(const char *str, t_sformat *f)
{
	size_t	len;

	if (!str)
	{
		len = sizeof(NULL_PRINTOUT_STR) - 1;
		if (f->precision >= 0 && len > (size_t)f->precision)
			len = 0;
		sprint(NULL_PRINTOUT_STR, len, f);
	}
	else
	{
		len = ft_strlen(str);
		if (f->precision >= 0 && len > (size_t)f->precision)
			len = f->precision;
		sprint(str, len, f);
	}
}

static void	sprint(const char *str, size_t len, t_sformat *f)
{
	if (!f->minus && f->width > len)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
				max_size(f, f->width - len));
	f->sprinted += ft_sputnstr(&f->str[f->sprinted], str, max_size(f, len));
	if (f->minus && f->width > len)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
				max_size(f, f->width - len));
}
