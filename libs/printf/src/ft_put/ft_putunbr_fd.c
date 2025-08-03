/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:50:07 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:29:50 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_applyprecision - Apply precision formatting with complex width handling
** @n: Unsigned number to format
** @fd: File descriptor to write to
** @flags: Formatting flags containing width and precision
**
** Handles precision formatting when precision is greater than number length.
** Manages complex interactions between width, precision, and alignment for
** unsigned integers. Applies width padding and precision zero-padding in the
** correct order. Handles both left and right alignment cases with proper
** width calculations. No sign handling needed for unsigned values.
** Returns the number of characters written.
*/
static int	ft_applyprecision(unsigned int n, int fd, t_flglst *flags)
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
	/* Precision zero-padding (right-aligned or no width) */
	while ((!width && prec -> value-- > ft_uintlen(n))
		|| (width && !ft_flgfind(flags, ALIGN)
			&& prec -> value-- > ft_uintlen(n)))
		len += ft_putchar_fd('0', fd, NULL);
	/* Left-aligned precision zeros with width adjustment */
	while (ft_flgfind(flags, ALIGN) && width -> value--
		&& prec -> value-- > ft_uintlen(n))
		len += ft_putchar_fd('0', fd, NULL);
	/* Additional left-aligned precision zeros */
	while (ft_flgfind(flags, ALIGN)
		&& prec -> value-- > ft_uintlen(n))
		len += ft_putchar_fd('0', fd, NULL);
	return (len);
}

/*
** ft_precision - Handle precision formatting for unsigned integer output
** @n: Unsigned number to format
** @fd: File descriptor to write to
** @flags: Formatting flags containing precision and width
**
** Determines whether to apply complex precision formatting or simple width
** formatting based on precision value relative to number length. If precision
** is greater than number length, uses complex precision handling. Otherwise,
** applies standard width formatting. Special case handling for zero values
** with precision formatting. No sign considerations for unsigned integers.
** Returns characters written.
*/
static int	ft_precision(unsigned int n, int fd, t_flglst *flags)
{
	int			len;		/* Characters written counter */
	t_flglst	*width;		/* Width flag pointer */

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	if (ft_flgfind(flags, PREC)-> value >= ft_uintlen(n))	/* Complex precision */
	{
		len += ft_applyprecision(n, fd, flags);
		if (n == 0)					/* Special zero case */
			len += ft_putchar_fd('0' + (n % 10), fd, NULL);
	}
	else							/* Simple width formatting */
	{
		/* Right-aligned width padding */
		while (!ft_flgfind(flags, ALIGN)
			&& width && width -> value-- > ft_uintlen(n))
			len += ft_putchar_fd(' ', fd, NULL);
		if (ft_flgfind(flags, ALIGN))			/* Adjust width for left-align */
			width -> value--;
		if (n == 0 && width)				/* Zero padding case */
			len += ft_putchar_fd(' ', fd, NULL);
	}
	return (len);
}

/*
** ft_preprocflags - Apply preprocessing formatting before digit output
** @n: Unsigned number to format
** @fd: File descriptor to write to
** @flags: Formatting flags for width, precision, alignment, zero-padding
**
** Handles preprocessing formatting logic before printing actual digits.
** Adjusts width calculations for sign characters (though SIGN/SPACE flags
** don't apply to unsigned integers, the code handles them defensively).
** Routes to either standard width formatting (no precision) or precision-based
** formatting. Manages space padding and zero padding in the correct order
** based on alignment and zero flags. Returns characters written during preprocessing.
*/
static int	ft_preprocflags(unsigned int n, int fd, t_flglst *flags)
{
	int			len;		/* Characters written counter */
	t_flglst	*width;		/* Width flag pointer */

	len = 0;
	width = ft_flgfind(flags, 0);
	/* Defensive width adjustment (SIGN/SPACE not meaningful for unsigned) */
	if (width && (ft_flgfind(flags, SIGN) || ft_flgfind(flags, SPACE)) && n > 0)
		width -> value--;
	if (!ft_flgfind(flags, PREC))			/* No precision specified */
	{
		/* Space padding (right-aligned, no zero flag) */
		while (!ft_flgfind(flags, ALIGN) && !ft_flgfind(flags, ZERO)
			&& width && width -> value-- > ft_uintlen(n))
			len += ft_putchar_fd(' ', fd, NULL);
		/* Zero padding (right-aligned with zero flag) */
		while (!ft_flgfind(flags, ALIGN) && ft_flgfind(flags, ZERO)
			&& width && width -> value-- > ft_uintlen(n))
			len += ft_putchar_fd('0', fd, NULL);
	}
	else						/* Precision specified */
		len += ft_precision(n, fd, flags);
	return (len);
}

/*
** ft_postprocflags - Apply post-processing formatting after digit output
** @n: Unsigned number that was formatted
** @fd: File descriptor to write to
** @flags: Formatting flags for width and alignment
**
** Handles left-aligned formatting by adding trailing spaces after the number
** digits have been printed. Only applies when the ALIGN flag (left-alignment)
** is present. Adjusts width calculations for precision formatting cases.
** Returns the number of characters written for trailing padding.
*/
static int	ft_postprocflags(unsigned int n, int fd, t_flglst *flags)
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
		&& width -> value-- > ft_uintlen(n))
		len += ft_putchar_fd(' ', fd, NULL);
	return (len);
}

/*
** ft_putunbr_fd - Write unsigned integer to file descriptor with printf formatting
** @n: Unsigned integer value to print
** @fd: File descriptor to write to
** @flags: Complete set of formatting flags (width, precision, alignment, etc.)
**
** Main unsigned integer printing function that handles all printf formatting for %u.
** Unlike signed integer printing, no sign handling or INT_MIN special cases needed.
** Coordinates preprocessing (width/padding), recursive digit output, and postprocessing
** (left-alignment). Handles precision-based zero suppression where zero values
** with zero precision don't print digits. Uses recursion for digit extraction
** from most significant to least significant. Simpler than signed version due to
** no negative number complications. Returns total characters written.
*/
int	ft_putunbr_fd(unsigned int n, int fd, t_flglst *flags)
{
	int	len;		/* Characters written counter */

	len = 0;
	len += ft_preprocflags(n, fd, flags);		/* Apply preprocessing */
	if (n > 9)					/* Recursive digit output */
		len += ft_putunbr_fd(n / 10, fd, NULL);
	/* Print current digit (unless zero with zero precision) */
	if (n != 0 || !ft_flgfind(flags, PREC))
		len += ft_putchar_fd('0' + (n % 10), fd, NULL);
	len += ft_postprocflags(n, fd, flags);		/* Apply postprocessing */
	return (len);
}
