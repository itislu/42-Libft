/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:12:35 by ldulling          #+#    #+#             */
/*   Updated: 2025/01/29 09:05:25 by ldulling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_isspace function checks if the passed character is a whitespace
 * character.
 * A whitespace character is one of the following:
 *   space, form feed, new line, carriage ret, horizontal tab, vertical tab
 *   ' '    '\f'       '\n'      '\r'          '\t'            '\v'
 *
 * @param c    The character to check.
 *
 * @return     Returns 1 if the character is a whitespace character,
 *             0 otherwise.
 *
 */
int	ft_isspace(int c)
{
	if (ft_strchr(WHITESPACE, c))
		return (1);
	return (0);
}
