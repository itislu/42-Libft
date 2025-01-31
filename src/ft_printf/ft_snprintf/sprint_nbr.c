/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:55 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/31 14:27:00 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static unsigned int	nbrlen(long nbr, t_sformat *f);
static unsigned int	fullnbrlen(long nbr, unsigned int len_nbr, t_sformat *f);
static void			sprint_prefix(long nbr, t_sformat *f);
static void			sprint_nbr_in_correct_base(long nbr, t_sformat *f);

void	sprint_nbr(long nbr, t_sformat *f)
{
	char			padding;
	unsigned int	len_nbr;
	unsigned int	len_full;

	padding = ' ';
	if (f->zero && !f->minus && f->precision < 0)
		padding = '0';
	len_nbr = nbrlen(nbr, f);
	len_full = fullnbrlen(nbr, len_nbr, f);
	if (padding == '0' && f->specifier != 'u')
		sprint_prefix(nbr, f);
	if (!f->minus && f->width > len_full)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], padding,
				max_size(f, f->width - len_full));
	if (padding == ' ' && f->specifier != 'u'
		&& !(nbr == 0 && f->precision == 0))
		sprint_prefix(nbr, f);
	if (f->precision > (int)len_nbr)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], '0',
				max_size(f, f->precision - len_nbr));
	if (!(nbr == 0 && f->precision == 0))
		sprint_nbr_in_correct_base(nbr, f);
	if (f->minus && f->width > len_full)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
				max_size(f, f->width - len_full));
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
