/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_snprintf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:27:24 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/31 16:44:55 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_SNPRINTF_H
# define _FT_SNPRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_sformat
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
	char			*str;
	size_t			size;
	size_t			sprinted;
}	t_sformat;

bool	check_args(char *str, size_t size, const char *format, t_sformat *f);
void	parseandsprint(const char *format, size_t *i, t_sformat *f, \
						va_list *ap);
void	sprint_argument(t_sformat *f, va_list *ap);
void	sprint_char(unsigned char c, t_sformat *f);
void	sprint_nbr(long nbr, t_sformat *f);
void	sprint_nbr_padding_left(t_sformat *f, char padding, \
								unsigned int len_full);
void	sprint_nbr_padding_right(t_sformat *f, unsigned int len_full);
void	sprint_nbr_zero_padding(t_sformat *f, unsigned int len_nbr);
void	sprint_parsed(const char *format, size_t parsed, t_sformat *f);
void	sprint_ptr(size_t ptr, t_sformat *f);
void	sprint_ptr_padding_left(t_sformat *f, unsigned int len_full);
void	sprint_ptr_padding_right(t_sformat *f, unsigned int len_full);
void	sprint_ptr_prefix(t_sformat *f);
void	sprint_ptr_zero_padding(t_sformat *f, unsigned int len_ptr, \
								unsigned int len_full);
void	sprint_str(const char *str, t_sformat *f);
size_t	max_size(t_sformat *f, size_t size);
void	reset_sformat(t_sformat *f);
size_t	set_sformat(const char *format, size_t *i, t_sformat *f, va_list *ap);

#endif
