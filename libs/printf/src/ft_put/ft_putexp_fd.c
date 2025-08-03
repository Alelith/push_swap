/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexp_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:02:40 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:10:14 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_putexp_fd - Print scientific notation exponent to file descriptor
** @e: Exponent value to print
** @fd: File descriptor to write to
** @upp: Flag for uppercase format (E vs e)
**
** Prints the exponent part of scientific notation format. Outputs 'E' or 'e'
** followed by the sign (+ or -) and the exponent value. Used in scientific
** notation formatting for %e, %E format specifiers. Returns the total
** number of characters written.
*/
int	ft_putexp_fd(int e, int fd, int upp)
{
	int	len;		/* Characters written counter */

	len = 0;
	/* Print 'E' or 'e' based on uppercase flag */
	if (upp)
		len += ft_putchar_fd('E', fd, NULL);
	else
		len += ft_putchar_fd('e', fd, NULL);
	
	/* Print sign and exponent value */
	if (e < 0)				/* Negative exponent */
	{
		len += ft_putchar_fd('-', fd, NULL);
		e = -e;				/* Make positive for printing */
	}
	else					/* Positive exponent */
		len += ft_putchar_fd('+', fd, NULL);
	len += ft_putnbr_fd(e, fd, NULL);	/* Print exponent value */
	return (len);
}
