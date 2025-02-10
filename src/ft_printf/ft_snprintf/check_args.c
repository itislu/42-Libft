/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:45:40 by ldulling          #+#    #+#             */
/*   Updated: 2025/02/10 12:20:46 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_snprintf.h"
#include <stddef.h>

bool	check_args(char *str, size_t size, const char *format, t_sformat *f)
{
	if (format == NULL)
	{
		if (size > 0)
			str[0] = '\0';
		f->chars_needed = -1;
		return (false);
	}
	if (size == 0)
	{
		f->chars_needed = 0;
		return (false);
	}
	return (true);
}
