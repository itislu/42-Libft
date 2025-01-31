/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:55 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/31 17:36:11 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_snprintf.h"
#include "libft.h"

static unsigned int	nbrlen(long nbr, t_sformat *f);
static unsigned int	fullnbrlen(long nbr, unsigned int len_nbr, t_sformat *f);
static void			sprint_prefix(long nbr, t_sformat *f);
static void			sprint_nbr_in_correct_base(long nbr, t_sformat *f);

void	sprint_nbr(long nbr, t_sformat *f)
{
	unsigned int	len_nbr = nbrlen(nbr, f);
	unsigned int	len_full = fullnbrlen(nbr, len_nbr, f);
	char			padding;
	
	len_nbr = nbrlen(nbr, f);
	len_full = fullnbrlen(nbr, len_nbr, f);
	if (f->zero && !f->minus && f->precision < 0)
		padding = '0';
	else
		padding = ' ';
	if (padding == '0' && f->specifier != 'u')
		sprint_prefix(nbr, f);
	sprint_nbr_padding_left(f, padding, len_full);
	if (padding == ' ' && f->specifier != 'u'
		&& !(nbr == 0 && f->precision == 0))
		sprint_prefix(nbr, f);
	sprint_nbr_zero_padding(f, len_nbr);
	if (!(nbr == 0 && f->precision == 0))
		sprint_nbr_in_correct_base(nbr, f);
	sprint_nbr_padding_right(f, len_full);
}

static unsigned int	nbrlen(long nbr, t_sformat *f)
{
	unsigned int	base;
	unsigned int	len_nbr;

	if (ft_strchr("xX", f->specifier))
		base = 16;
	else
		base = 10;
	if (nbr == 0 && f->precision != 0)
		len_nbr = 1;
	else
	{
		len_nbr = 0;
		while (nbr)
		{
			nbr /= base;
			len_nbr++;
		}
	}
	return (len_nbr);
}

static unsigned int	fullnbrlen(long nbr, unsigned int len_nbr, t_sformat *f)
{
	unsigned int	len_full;

	len_full = len_nbr;
	if ((int)len_nbr < f->precision)
		len_full = f->precision;
	if (!ft_strchr("uxX", f->specifier))
		if (!(nbr == 0 && f->precision == 0))
			if (nbr < 0 || f->plus || f->space)
				len_full++;
	if (ft_strchr("xX", f->specifier))
		if (f->hash && nbr != 0)
			len_full += sizeof("0x") - 1;
	return (len_full);
}

static void	sprint_prefix(long nbr, t_sformat *f)
{
	if (ft_strchr("xX", f->specifier))
	{
		if (f->hash && nbr != 0)
		{
			if (f->specifier == 'x')
				f->sprinted += ft_sputnstr(&f->str[f->sprinted], "0x",
						max_size(f, 2));
			else if (f->specifier == 'X')
				f->sprinted += ft_sputnstr(&f->str[f->sprinted], "0X",
						max_size(f, 2));
		}
	}
	else
	{
		if (nbr < 0)
			f->sprinted += ft_sputnchar(&f->str[f->sprinted], '-',
					max_size(f, 1));
		else if (f->plus)
			f->sprinted += ft_sputnchar(&f->str[f->sprinted], '+',
					max_size(f, 1));
		else if (f->space)
			f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
					max_size(f, 1));
	}
}

static void	sprint_nbr_in_correct_base(long nbr, t_sformat *f)
{
	if (f->specifier == 'x')
		f->sprinted += ft_snputnbr_base(&f->str[f->sprinted], nbr,
				"0123456789abcdef", f->size - f->sprinted);
	else if (f->specifier == 'X')
		f->sprinted += ft_snputnbr_base(&f->str[f->sprinted], nbr,
				"0123456789ABCDEF", f->size - f->sprinted);
	else if (nbr < 0)
		f->sprinted += ft_snputnbr_base(&f->str[f->sprinted], -nbr,
				"0123456789", f->size - f->sprinted);
	else
		f->sprinted += ft_snputnbr_base(&f->str[f->sprinted], nbr,
				"0123456789", f->size - f->sprinted);
}
