/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprint_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:27:12 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/31 14:57:39 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stddef.h>

static void			sprint_nullptr(t_sformat *f);
static unsigned int	ptrlen(size_t ptr);
static unsigned int	fullptrlen(unsigned int len_ptr, t_sformat *f);
static void			sputhex(size_t ptr, t_sformat *f);

void	sprint_ptr(size_t ptr, t_sformat *f)
{
	unsigned int	len_ptr;
	unsigned int	len_full;

	if (!ptr)
		return (sprint_nullptr(f));
	len_ptr = ptrlen(ptr);
	len_full = fullptrlen(len_ptr, f);
	if (!f->minus && f->width > len_full && !(f->zero && f->precision < 0))
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
				max_size(f, f->width - len_full));
	if (f->plus)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], '+', max_size(f, 1));
	else if (f->space)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ', max_size(f, 1));
	f->sprinted += ft_sputnstr(&f->str[f->sprinted], "0x", max_size(f, 2));
	if (f->precision > (int)len_ptr)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], '0',
				max_size(f, f->precision - len_ptr));
	else if (f->zero && !f->minus && f->precision < 0 && f->width > len_full)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], '0',
				max_size(f, f->width - len_full));
	sputhex(ptr, f);
	if (f->minus && f->width > len_full)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
				max_size(f, f->width - len_full));
}

static void	sprint_nullptr(t_sformat *f)
{
	unsigned int	len;

	len = sizeof(NULL_PRINTOUT_PTR) - 1;
	if (!f->minus && f->width > len)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
				max_size(f, f->width - len));
	f->sprinted += ft_sputnstr(&f->str[f->sprinted], NULL_PRINTOUT_PTR,
			max_size(f, len));
	if (f->minus && f->width > len)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ' ',
				max_size(f, f->width - len));
}

static unsigned int	ptrlen(size_t ptr)
{
	unsigned int	len_ptr;

	len_ptr = 0;
	while (ptr)
	{
		ptr /= 16;
		len_ptr++;
	}
	return (len_ptr);
}

static unsigned int	fullptrlen(unsigned int len_ptr, t_sformat *f)
{
	unsigned int	len_full;

	len_full = len_ptr;
	if ((int)len_full < f->precision)
		len_full = f->precision;
	if (f->plus || f->space)
		len_full++;
	len_full += sizeof("0x") - 1;
	return (len_full);
}

static void	sputhex(size_t ptr, t_sformat *f)
{
	if (ptr >= 16)
		sputhex(ptr / 16, f);
	ptr %= 16;
	if (ptr >= 10)
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ptr - 10 + 'a',
				max_size(f, 1));
	else
		f->sprinted += ft_sputnchar(&f->str[f->sprinted], ptr + '0',
				max_size(f, 1));
}
