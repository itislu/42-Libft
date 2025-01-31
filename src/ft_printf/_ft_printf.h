/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:27:30 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/31 18:24:56 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_format
{
	bool			hash;
	bool			plus;
	bool			space;
	int				minus;
	bool			zero;
	unsigned int	width;
	int				precision;
	char			specifier;
	bool			unresolved;
	int				fd;
}	t_format;

size_t			parseandprint(const char *format, size_t *i, t_format *f, \
								va_list *ap);
size_t			print_argument(t_format *f, va_list *ap);
unsigned int	print_char(unsigned char c, t_format *f);
unsigned int	print_nbr(long nbr, t_format *f);
unsigned int	print_nbr_padding_left(t_format *f, char padding, \
										unsigned int len_full);
unsigned int	print_nbr_padding_right(t_format *f, unsigned int len_full);
unsigned int	print_nbr_zero_padding(t_format *f, unsigned int len_nbr);
size_t			print_parsed(const char *format, size_t parsed, t_format *f);
unsigned int	print_ptr(size_t ptr, t_format *f);
unsigned int	print_ptr_padding_left(t_format *f, unsigned int len_full);
unsigned int	print_ptr_padding_right(t_format *f, unsigned int len_full);
unsigned int	print_ptr_prefix(t_format *f);
unsigned int	print_ptr_zero_padding(t_format *f, unsigned int len_ptr, \
										unsigned int len_full);
size_t			print_str(const char *str, t_format *f);
void			reset_format(t_format *f);
size_t			set_format(const char *format, size_t *i, t_format *f, \
							va_list *ap);

#endif
