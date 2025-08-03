/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:47:21 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:20:11 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_applyprecision - Apply precision formatting for hexadecimal output
** @n: Number to format
** @fd: File descriptor to write to
** @flags: Formatting flags
**
** Handles complex precision formatting for hexadecimal numbers.
** Manages width padding and zero-padding based on precision requirements.
** Considers alignment flags to determine padding placement.
** Returns the number of characters written.
*/
static int	ft_applyprecision(unsigned long n, int fd, t_flglst *flags)
{
	int			len;		/* Characters written counter */
	t_flglst	*width;		/* Width flag pointer */
	t_flglst	*prec;		/* Precision flag pointer */

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	prec = ft_flgfind(flags, PREC);
	/* Right-aligned width padding before precision zeros */
	while (width && !ft_flgfind(flags, ALIGN)
		&& width -> value-- > prec -> value)
		len += ft_putchar_fd(' ', fd, NULL);
	/* Zero padding for precision (right-aligned or no width) */
	while ((!width && prec -> value-- > ft_hexlen(n))
		|| (width && !ft_flgfind(flags, ALIGN)
			&& prec -> value-- > ft_hexlen(n)))
		len += ft_putchar_fd('0', fd, NULL);
	/* Zero padding for left-aligned precision */
	while (ft_flgfind(flags, ALIGN)
		&& prec -> value-- > ft_hexlen(n))
	{
		len += ft_putchar_fd('0', fd, NULL);
		if (width -> value)
			width -> value--;
	}
	return (len);
}

/*
** ft_precision - Handle precision formatting for hexadecimal output
** @n: Number to format
** @fd: File descriptor to write to
** @flags: Formatting flags
**
** Determines whether precision requires zero-padding or just width adjustment.
** If precision is greater than number length, applies complex precision formatting.
** Otherwise, handles simple width padding for right-aligned output.
** Returns the number of characters written.
*/
static int	ft_precision(unsigned long n, int fd, t_flglst *flags)
{
	int			len;		/* Characters written counter */
	t_flglst	*prec;		/* Precision flag pointer */
	t_flglst	*width;		/* Width flag pointer */

	len = 0;
	prec = ft_flgfind(flags, PREC);
	width = ft_flgfind(flags, WIDTH);
	if (prec -> value >= ft_hexlen(n))		/* Precision padding needed */
		len += ft_applyprecision(n, fd, flags);
	else						/* Simple width padding */
	{
		/* Right-aligned width padding */
		while (!ft_flgfind(flags, ALIGN)
			&& width && width -> value-- > ft_hexlen(n))
			len += ft_putchar_fd(' ', fd, NULL);
		/* Adjust width for left-aligned case */
		if (ft_flgfind(flags, ALIGN) && width -> value < prec -> value)
			width -> value--;
	}
	return (len);
}

/*
** ft_preprocflags - Preprocess formatting flags before hex output
** @n: Number to format
** @fd: File descriptor to write to
** @flags: Formatting flags
**
** Handles preprocessing of flags before actual hexadecimal digit output.
** Currently focuses on precision flag handling. Acts as a dispatcher
** for different formatting modes. Returns characters written during preprocessing.
*/
static int	ft_preprocflags(unsigned long n, int fd, t_flglst *flags)
{
	int	len;			/* Characters written counter */

	len = 0;
	if (ft_flgfind(flags, PREC))	/* Apply precision formatting */
		len += ft_precision(n, fd, flags);
	return (len);
}

/*
** ft_puthex_fd - Write hexadecimal number to file descriptor
** @p: Number to convert and write
** @fd: File descriptor to write to
** @upp: Case flag (0 for lowercase, 1 for uppercase)
** @flags: Formatting flags for width, precision, alignment
**
** Recursively converts and writes a number in hexadecimal format.
** Supports both lowercase (0-9a-f) and uppercase (0-9A-F) output.
** Applies formatting flags for width, precision, and alignment.
** Handles special case of zero with precision formatting.
** Returns the total number of characters written.
*/
int	ft_puthex_fd(unsigned long p, int fd, int upp, t_flglst *flags)
{
	int				len;	/* Characters written counter */
	char			*hex;	/* Hex digit character set */

	len = 0;
	if (!upp)				/* Select character set */
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	len += ft_preprocflags(p, fd, flags);	/* Apply formatting */
	if (p > 15)				/* Recursive case */
		len += ft_puthex_fd(p / 16, fd, upp, NULL);
	/* Output digit (unless zero with precision) */
	if (p > 0 || !ft_flgfind(flags, PREC))
		len += ft_putchar_fd(hex[p % 16], fd, NULL);
	return (len);
}
