/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:55 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/30 07:43:23 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static unsigned int	nbrlen(long nbr, t_format *f);
static unsigned int	fullnbrlen(long nbr, unsigned int len_nbr, t_format *f);
static unsigned int	print_prefix(long nbr, t_format *f);
static unsigned int	print_nbr_in_correct_base(long nbr, t_format *f);

unsigned int	print_nbr(long nbr, t_format *f)
{
	char			padding;
	unsigned int	len_nbr;
	unsigned int	len_full;
	unsigned int	printed;

	padding = ' ';
	if (f->zero && !f->minus && f->precision < 0)
		padding = '0';
	len_nbr = nbrlen(nbr, f);
	len_full = fullnbrlen(nbr, len_nbr, f);
	printed = 0;
	if (padding == '0' && f->specifier != 'u')
		printed += print_prefix(nbr, f);
	if (!f->minus && f->width > len_full)
		printed += ft_putnchar_fd(padding, f->width - len_full, f->fd);
	if (padding == ' ' && f->specifier != 'u'
		&& !(nbr == 0 && f->precision == 0))
		printed += print_prefix(nbr, f);
	if (f->precision > (int)len_nbr)
		printed += ft_putnchar_fd('0', f->precision - len_nbr, f->fd);
	if (!(nbr == 0 && f->precision == 0))
		printed += print_nbr_in_correct_base(nbr, f);
	if (f->minus && f->width > len_full)
		printed += ft_putnchar_fd(' ', f->width - len_full, f->fd);
	return (printed);
}

static unsigned int	nbrlen(long nbr, t_format *f)
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

static unsigned int	fullnbrlen(long nbr, unsigned int len_nbr, t_format *f)
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
			len_full += ft_strlen("0x");
	return (len_full);
}

static unsigned int	print_prefix(long nbr, t_format *f)
{
	unsigned int	printed;

	printed = 0;
	if (ft_strchr("xX", f->specifier))
	{
		if (f->hash && nbr != 0)
		{
			if (f->specifier == 'x')
				printed += ft_putnstr_fd("0x", 2, f->fd);
			else if (f->specifier == 'X')
				printed += ft_putnstr_fd("0X", 2, f->fd);
		}
	}
	else
	{
		if (nbr < 0)
			printed += ft_putnchar_fd('-', 1, f->fd);
		else if (f->plus)
			printed += ft_putnchar_fd('+', 1, f->fd);
		else if (f->space)
			printed += ft_putnchar_fd(' ', 1, f->fd);
	}
	return (printed);
}

static unsigned int	print_nbr_in_correct_base(long nbr, t_format *f)
{
	unsigned int	printed;

	printed = 0;
	if (f->specifier == 'x')
		printed += ft_putnbr_base_fd(nbr, "0123456789abcdef", f->fd);
	else if (f->specifier == 'X')
		printed += ft_putnbr_base_fd(nbr, "0123456789ABCDEF", f->fd);
	else if (nbr < 0)
		printed += ft_putnbr_base_fd(-nbr, "0123456789", f->fd);
	else
		printed += ft_putnbr_base_fd(nbr, "0123456789", f->fd);
	return (printed);
}
