/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_record.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:03:34 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/10 20:53:59 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_snprintf.h"
#include "libft.h"
#include <stddef.h>
#include <sys/param.h>

static size_t	available_size(const t_sformat *f, size_t size);
static void		record(t_sformat *f, size_t target, size_t actual);

void	strcpy_record(t_sformat *f, const char *src, size_t target_len)
{
	const size_t	len = available_size(f, target_len);
	char			*dest;

	dest = &f->str[f->sprinted];
	record(f, target_len, ft_sputnstr(dest, src, len));
}

void	strcpy_char_record(t_sformat *f, unsigned char c, size_t target_amount)
{
	const size_t	amount = available_size(f, target_amount);
	char			*dest;

	dest = &f->str[f->sprinted];
	record(f, target_amount, ft_sputnchar(dest, c, amount));
}

void	strcpy_nbr_record(t_sformat *f, long nbr, const char *base)
{
	const size_t		maxlen = f->size - f->sprinted;
	const unsigned int	nbr_len = ft_nbrlen_base(nbr, ft_strlen(base));
	char				*dest;

	dest = &f->str[f->sprinted];
	record(f, nbr_len, ft_snputnbr_base(dest, nbr, base, maxlen));
}

static size_t	available_size(const t_sformat *f, size_t size)
{
	return (ft_min_u(size, f->size - f->sprinted));
}

static void	record(t_sformat *f, size_t target, size_t actual)
{
	f->sprinted += MIN(target, actual);
	f->chars_needed += target;
}
