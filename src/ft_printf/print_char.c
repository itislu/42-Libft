/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:51 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/30 06:57:23 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

unsigned int	print_char(unsigned char c, t_format *f)
{
	unsigned int	printed;

	printed = 0;
	if (!f->minus && f->width > 1)
		printed += ft_putnchar_fd(' ', f->width - 1, f->fd);
	printed += ft_putnchar_fd(c, 1, f->fd);
	if (f->minus && f->width > 1)
		printed += ft_putnchar_fd(' ', f->width - 1, f->fd);
	return (printed);
}
