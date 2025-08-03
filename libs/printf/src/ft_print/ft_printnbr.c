/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:53:19 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:20:12 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_printnbr - Print integer with format type and flags
** @nbr: Integer value to print
** @type: Format specifier type ('i', 'd', 'u', 'o')
** @flags: Formatting flags for width, precision, etc.
**
** Dispatches integer printing to appropriate format-specific function
** based on the type specifier. Handles signed decimal (%d, %i),
** unsigned decimal (%u), and octal (%o) formats. Applies formatting
** flags and cleans up flag list after use. Returns number of characters printed.
*/
int	ft_printnbr(int nbr, char type, t_flglst *flags)
{
	int	len;		/* Characters printed counter */

	len = 0;
	if (type == 'i' || type == 'd')		/* Signed decimal formats */
		len = ft_putnbr_fd(nbr, 1, flags);
	else if (type == 'u')			/* Unsigned decimal format */
		len = ft_putunbr_fd(nbr, 1, flags);
	else if (type == 'o')			/* Octal format */
		len = ft_putoct_fd(nbr, 1);
	ft_flgclear(&flags);			/* Clean up flag list */
	return (len);
}
