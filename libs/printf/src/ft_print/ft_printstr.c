/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:15:39 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:20:13 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_printstr - Print string with formatting flags
** @str: String to print (may be NULL)
** @flags: Formatting flags for width, precision, alignment
**
** Prints a string applying formatting flags. Handles NULL pointers by
** printing "(null)" if precision allows, or empty string otherwise.
** Applies width, precision, and alignment flags for proper formatting.
** Used for %s format specifier. Cleans up flag list after use.
** Returns number of characters printed.
*/
int	ft_printstr(char *str, t_flglst *flags)
{
	int	len;		/* Characters printed counter */

	if (str)				/* Valid string pointer */
		len = ft_putstr_fd(str, 1, flags);
	else if (!ft_flgfind(flags, PREC)	/* NULL with no precision limit */
		|| (ft_flgfind(flags, PREC)	/* Or precision >= 6 for "(null)" */
			&& ft_flgfind(flags, PREC)-> value >= 6))
		len = ft_putstr_fd("(null)", 1, flags);
	else					/* NULL with precision < 6 */
		len = ft_putstr_fd("", 1, flags);
	ft_flgclear(&flags);			/* Clean up flag list */
	return (len);
}
