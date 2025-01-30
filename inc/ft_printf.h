/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:26:08 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/30 07:47:29 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# define SPECIFIERS				"cspdiuxX%"
# define FLAGS					"#+- 0"
# define NULL_PRINTOUT_PTR		"(nil)"
# define NULL_PRINTOUT_STR		"(null)"
# define FROM_NEGATIVE_WIDTH	2
# define NO_PRECISION_SET		-1
# define NEGATIVE_PRECISION		-2

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

\
/* ft_printf + ft_dprintf */

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
size_t			parseandprint(const char *format, size_t *i, t_format *f, \
								va_list *ap);
size_t			print_argument(t_format *f, va_list *ap);
unsigned int	print_char(unsigned char c, t_format *f);
unsigned int	print_nbr(long nbr, t_format *f);
size_t			print_parsed(const char *format, size_t parsed, t_format *f);
unsigned int	print_ptr(size_t ptr, t_format *f);
size_t			print_str(const char *str, t_format *f);
void			reset_format(t_format *f);
size_t			set_format(const char *format, size_t *i, t_format *f, \
							va_list *ap);

\
/* ft_snprintf + ft_vsnprintf */

int				ft_snprintf(char *str, size_t size, const char *format, ...);
int				ft_vsnprintf(char *str, size_t size, const char *format, \
								va_list ap);
bool			check_args(char *str, size_t size, const char *format, \
							t_sformat *f);
void			parseandsprint(const char *format, size_t *i, t_sformat *f, \
								va_list *ap);
void			sprint_argument(t_sformat *f, va_list *ap);
void			sprint_char(unsigned char c, t_sformat *f);
void			sprint_nbr(long nbr, t_sformat *f);
void			sprint_parsed(const char *format, size_t parsed, t_sformat *f);
void			sprint_ptr(size_t ptr, t_sformat *f);
void			sprint_str(const char *str, t_sformat *f);
size_t			max_size(t_sformat *f, size_t size);
void			reset_sformat(t_sformat *f);
size_t			set_sformat(const char *format, size_t *i, t_sformat *f, \
							va_list *ap);

\
/* shared */
int				return_value(size_t printed);

#endif
