/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf_shared.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:27:27 by ldulling          #+#    #+#             */
/*   Updated: 2025/03/08 00:56:55 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_SHARED_H
# define _FT_PRINTF_SHARED_H

# include <stddef.h>

# define SPECIFIERS				"cspdiouxX%"
# define FLAGS					"#+- 0"
# define NULL_PRINTOUT_PTR		"(nil)"
# define NULL_PRINTOUT_STR		"(null)"
# define FROM_NEGATIVE_WIDTH	2
# define NO_PRECISION_SET		-1
# define NEGATIVE_PRECISION		-2

int	return_value(size_t ret);

#endif
