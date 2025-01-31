/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_pad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:46:34 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/31 16:58:16 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_printf.h"
#include "libft.h"

unsigned int	print_nbr_padding_left(t_format *f, char padding, \
										unsigned int len_full)
{
	if (!f->minus && f->width > len_full)
		return (ft_putnchar_fd(padding, f->width - len_full, f->fd));
	return (0);
}

unsigned int	print_nbr_padding_right(t_format *f, unsigned int len_full)
{
	if (f->minus && f->width > len_full)
		return (ft_putnchar_fd(' ', f->width - len_full, f->fd));
	return (0);
}

unsigned int	print_nbr_zero_padding(t_format *f, unsigned int len_nbr)
{
	if (f->precision > (int)len_nbr)
		return (ft_putnchar_fd('0', f->precision - len_nbr, f->fd));
	return (0);
}
