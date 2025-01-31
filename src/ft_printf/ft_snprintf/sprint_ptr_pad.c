/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_ptr_pad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:02:01 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/31 15:57:52 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_snprintf.h"
#include "libft.h"

void	sprint_ptr_padding_left(t_sformat *f, unsigned int len_full)
{
	if (!f->minus && f->width > len_full && !(f->zero && f->precision < 0))
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
				max_size(f, f->width - len_full));
}

void	sprint_ptr_padding_right(t_sformat *f, unsigned int len_full)
{
	if (f->minus && f->width > len_full)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
				max_size(f, f->width - len_full));
}

void	sprint_ptr_prefix(t_sformat *f)
{
	if (f->plus)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], '+', max_size(f, 1));
	else if (f->space)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ', max_size(f, 1));
	f->sprinted += ft_sputnstr(&f->str[f->sprinted], "0x", max_size(f, 2));
}

void	sprint_ptr_zero_padding(t_sformat *f, unsigned int len_ptr, \
								unsigned int len_full)
{
	if (f->precision > (int)len_ptr)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], '0',
				max_size(f, f->precision - len_ptr));
	else if (f->zero && !f->minus && f->precision < 0 && f->width > len_full)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], '0',
				max_size(f, f->width - len_full));
}
