/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:21:16 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:25:29 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_applyprecision - Apply precision formatting with complex width handling
** @n: Number to format (absolute value)
** @fd: File descriptor to write to
** @flags: Formatting flags containing width and precision
** @sign: Sign of the original number (1 for positive, -1 for negative)
**
** Handles precision formatting when precision is greater than number length.
** Manages complex interactions between width, precision, alignment, and sign.
** Applies width padding, sign placement, and precision zero-padding in the
** correct order. Handles both left and right alignment cases with proper
** width calculations accounting for sign characters.
** Returns the number of characters written.
*/
static int	ft_applyprecision(int n, int fd, t_flglst *flags, int sign)
{
	int			len;		/* Characters written counter */
	t_flglst	*width;		/* Width flag pointer */
	t_flglst	*prec;		/* Precision flag pointer */

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	prec = ft_flgfind(flags, PREC);
	/* Right-aligned width padding before sign and precision zeros */
	while (width && !ft_flgfind(flags, ALIGN)
		&& ((sign > 0 && width -> value-- > prec -> value)
			|| (sign < 0 && width -> value-- > prec -> value + 1)))
		len += ft_putchar_fd(' ', fd, NULL);
	len += ft_putsign_fd(flags, fd, sign);		/* Print sign */
	/* Precision zero-padding (right-aligned or no width) */
	while ((!width && prec -> value-- > ft_intlen(n))
		|| (width && !ft_flgfind(flags, ALIGN)
			&& prec -> value-- > ft_intlen(n)))
		len += ft_putchar_fd('0', fd, NULL);
	/* Left-aligned precision zeros with width adjustment */
	while (ft_flgfind(flags, ALIGN) && width -> value--
		&& prec -> value-- > ft_intlen(n))
		len += ft_putchar_fd('0', fd, NULL);
	/* Additional left-aligned precision zeros */
	while (ft_flgfind(flags, ALIGN)
		&& prec -> value-- > ft_intlen(n))
		len += ft_putchar_fd('0', fd, NULL);
	return (len);
}

/*
** ft_precision - Handle precision formatting for integer output
** @n: Number to format (absolute value)
** @fd: File descriptor to write to
** @flags: Formatting flags containing precision and width
** @sign: Sign of the original number (1 for positive, -1 for negative)
**
** Determines whether to apply complex precision formatting or simple width
** formatting based on precision value relative to number length. If precision
** is greater than number length, uses complex precision handling. Otherwise,
** applies standard width formatting with sign handling. Special case handling
** for zero values with precision formatting. Returns characters written.
*/
static int	ft_precision(int n, int fd, t_flglst *flags, int sign)
{
	int			len;		/* Characters written counter */
	t_flglst	*width;		/* Width flag pointer */

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	if (ft_flgfind(flags, PREC)-> value >= ft_intlen(n))	/* Complex precision */
	{
		len += ft_applyprecision(n, fd, flags, sign);
		if (n == 0)					/* Special zero case */
			len += ft_putchar_fd('0' + (n % 10), fd, NULL);
	}
	else							/* Simple width formatting */
	{
		/* Right-aligned width padding */
		while (!ft_flgfind(flags, ALIGN)
			&& width && width -> value-- > ft_intlen(n * sign))
			len += ft_putchar_fd(' ', fd, NULL);
		if (sign < 0)					/* Negative sign */
			len += ft_putchar_fd('-', fd, NULL);
		if (ft_flgfind(flags, ALIGN))			/* Adjust width for left-align */
			width -> value--;
		if (n == 0 && width)				/* Zero padding case */
			len += ft_putchar_fd(' ', fd, NULL);
	}
	return (len);
}

/*
** ft_preprocflags - Apply preprocessing formatting before digit output
** @n: Number to format (absolute value)
** @fd: File descriptor to write to
** @flags: Formatting flags for width, precision, alignment, zero-padding
** @sign: Sign of the original number (1 for positive, -1 for negative)
**
** Handles preprocessing formatting logic before printing actual digits.
** Adjusts width calculations for sign characters when + or space flags are
** present. Routes to either standard width formatting (no precision) or
** precision-based formatting. Manages space padding, sign placement, and
** zero padding in the correct order based on alignment and zero flags.
** Returns the number of characters written during preprocessing.
*/
static int	ft_preprocflags(int n, int fd, t_flglst *flags, int sign)
{
	int			len;		/* Characters written counter */
	t_flglst	*width;		/* Width flag pointer */

	len = 0;
	width = ft_flgfind(flags, 0);
	/* Adjust width for explicit sign display */
	if (width && (ft_flgfind(flags, SIGN) || ft_flgfind(flags, SPACE)) && n > 0)
		width -> value--;
	if (!ft_flgfind(flags, PREC))			/* No precision specified */
	{
		/* Space padding (right-aligned, no zero flag) */
		while (!ft_flgfind(flags, ALIGN) && !ft_flgfind(flags, ZERO)
			&& width && width -> value-- > ft_intlen(n * sign))
			len += ft_putchar_fd(' ', fd, NULL);
		len += ft_putsign_fd(flags, fd, sign);	/* Print sign */
		/* Zero padding (right-aligned with zero flag) */
		while (!ft_flgfind(flags, ALIGN) && ft_flgfind(flags, ZERO)
			&& width && width -> value-- > ft_intlen(n * sign))
			len += ft_putchar_fd('0', fd, NULL);
	}
	else						/* Precision specified */
		len += ft_precision(n, fd, flags, sign);
	return (len);
}

/*
** ft_postprocflags - Apply post-processing formatting after digit output
** @n: Number that was formatted (absolute value)
** @fd: File descriptor to write to
** @flags: Formatting flags for width and alignment
** @sign: Sign of the original number (1 for positive, -1 for negative)
**
** Handles left-aligned formatting by adding trailing spaces after the number
** digits have been printed. Only applies when the ALIGN flag (left-alignment)
** is present. Adjusts width calculations for precision formatting cases.
** Returns the number of characters written for trailing padding.
*/
static int	ft_postprocflags(int n, int fd, t_flglst *flags, int sign)
{
	int			len;		/* Characters written counter */
	t_flglst	*width;		/* Width flag pointer */

	len = 0;
	width = ft_flgfind(flags, 0);
	/* Adjust width for precision formatting */
	if (ft_flgfind(flags, PREC) && width)
		width -> value++;
	/* Apply left-aligned trailing space padding */
	while (ft_flgfind(flags, ALIGN) && width
		&& width -> value-- > ft_intlen(n * sign))
		len += ft_putchar_fd(' ', fd, NULL);
	return (len);
}

/*
** ft_putnbr_fd - Write integer to file descriptor with printf formatting
** @n: Integer value to print
** @fd: File descriptor to write to
** @flags: Complete set of formatting flags (width, precision, alignment, etc.)
**
** Main integer printing function that handles all printf formatting for %d and %i.
** Special case handling for INT_MIN (-2147483648) to avoid overflow issues.
** Converts negative numbers to positive and tracks sign separately. Coordinates
** preprocessing (width/padding), recursive digit output, and postprocessing
** (left-alignment). Handles precision-based zero suppression where zero values
** with zero precision don't print digits. Uses recursion for digit extraction
** from most significant to least significant. Returns total characters written.
*/
int	ft_putnbr_fd(int n, int fd, t_flglst *flags)
{
	int	len;		/* Characters written counter */
	int	sign;		/* Sign of the number (1 or -1) */

	/* Special case: handle INT_MIN to avoid overflow */
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd, NULL));
	len = 0;
	sign = 1;
	if (n < 0)				/* Convert negative to positive */
	{
		n = -n;
		sign = -1;
	}
	len += ft_preprocflags(n, fd, flags, sign);	/* Apply preprocessing */
	if (n > 9)					/* Recursive digit output */
		len += ft_putnbr_fd(n / 10, fd, NULL);
	/* Print current digit (unless zero with zero precision) */
	if (n != 0 || !ft_flgfind(flags, PREC))
		len += ft_putchar_fd('0' + (n % 10), fd, NULL);
	len += ft_postprocflags(n, fd, flags, sign);	/* Apply postprocessing */
	return (len);
}
