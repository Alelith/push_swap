/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:23:45 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:10:11 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_putdouble_fd - Print a double/float value to file descriptor
** @d: Double value to print
** @fd: File descriptor to write to
**
** Prints a floating-point number with fixed precision (5 decimal places).
** Handles the integer and fractional parts separately. Applies basic
** rounding for the last decimal place. Used for %f format specifier
** in printf. Returns the total number of characters written.
*/
int	ft_putdouble_fd(double d, int fd)
{
	int	len;		/* Characters written counter */
	int	intpart;	/* Integer portion of the number */
	int	decimals;	/* Number of decimal places to print */

	len = 0;
	intpart = (int) d;			/* Extract integer part */
	decimals = 5;				/* Fixed precision */
	d = d - intpart;			/* Get fractional part */
	if (d < 0)				/* Handle negative fractional part */
		d = -d;
	len += ft_putnbr_fd(intpart, fd, NULL);	/* Print integer part */
	len += ft_putchar_fd('.', fd, NULL);	/* Print decimal point */
	
	/* Print decimal digits */
	while (decimals--)
	{
		d *= 10;			/* Shift decimal left */
		len += ft_putchar_fd(((int)d % 10) + '0', fd, NULL);
	}
	
	/* Simple rounding for the last digit */
	d *= 10;
	if (d - (int)d >= 0.5)			/* Round up if >= 0.5 */
		len += ft_putchar_fd(((int)d % 10) + 1 + '0', fd, NULL);
	else					/* Round down */
		len += ft_putchar_fd(((int)d % 10) + '0', fd, NULL);
	return (len);
}
