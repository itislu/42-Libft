/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_nbr_pad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:46:34 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/31 16:46:35 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_snprintf.h"
#include "libft.h"

void	sprint_nbr_padding_left(t_sformat *f, char padding, \
								unsigned int len_full)
{
	if (!f->minus && f->width > len_full)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], padding,
				max_size(f, f->width - len_full));
}

void	sprint_nbr_padding_right(t_sformat *f, unsigned int len_full)
{
	if (f->minus && f->width > len_full)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
				max_size(f, f->width - len_full));
}

void	sprint_nbr_zero_padding(t_sformat *f, unsigned int len_nbr)
{
	if (f->precision > (int)len_nbr)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], '0',
				max_size(f, f->precision - len_nbr));
}
