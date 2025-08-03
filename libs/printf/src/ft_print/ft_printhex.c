/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:00:12 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:22:55 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_putprefix - Print hexadecimal prefix (0x or 0X) when required
** @hex: Hexadecimal value to check (zero values don't get prefix)
** @type: Format specifier type ('p', 'x', 'X')
** @flags: Formatting flags (# flag triggers prefix for x/X)
**
** Prints the appropriate hexadecimal prefix based on format type and flags.
** For pointer type 'p', always prints "0x" for non-zero values.
** For hex types with # flag, prints "0x" for lowercase or "0X" for uppercase.
** Zero values don't get prefixes according to printf standard behavior.
** Returns the number of characters written (0 or 2).
*/
static int	ft_putprefix(unsigned long hex, char type, t_flglst *flags)
{
	int	len;		/* Characters written counter */

	len = 0;
	/* Print prefix only for non-zero values with pointer or # flag */
	if ((type == 'p' || ft_flgfind(flags, '#')) && hex)
	{
		if (type == 'p' && hex)			/* Pointer format */
			len += ft_putstr_fd("0x", 1, NULL);
		else if (!ft_isupper(type) && type != 'p')	/* Lowercase hex */
			len += ft_putstr_fd("0x", 1, NULL);
		else if (ft_isupper(type))		/* Uppercase hex */
			len += ft_putstr_fd("0X", 1, NULL);
	}
	return (len);
}

/*
** ft_precision - Handle precision-based width formatting for hexadecimal
** @flags: Formatting flags containing width and precision specifications
**
** Applies width formatting when precision is specified but doesn't require
** zero-padding of the actual number. Handles right-aligned spacing before
** the precision zeros are applied. This is a specialized case where width
** exceeds precision requirements. Returns characters written for spacing.
*/
static int	ft_precision(t_flglst *flags)
{
	int			len;		/* Characters written counter */
	t_flglst	*width;		/* Width flag pointer */

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	/* Apply right-aligned width padding before precision formatting */
	while (!ft_flgfind(flags, ALIGN)
		&& width && width -> value > ft_flgfind(flags, PREC)-> value)
	{
		len += ft_putchar_fd(' ', 1, NULL);	/* Space padding */
		width -> value--;			/* Decrease remaining width */
	}
	return (len);
}

/*
** ft_preprocflags - Apply preprocessing formatting before hex digit output
** @hex: Hexadecimal value to format
** @type: Format specifier type ('p', 'x', 'X')
** @flags: Formatting flags for width, precision, alignment, zero-padding
**
** Handles complex formatting logic before printing the actual hex digits.
** Manages width padding (space or zero), precision formatting, and prefix
** placement. Considers interaction between precision, width, alignment, and
** zero-padding flags. The prefix is printed after width calculations but
** before the actual digits. Returns total characters written for formatting.
*/
static int	ft_preprocflags(unsigned long hex, char type, t_flglst *flags)
{
	int			len;		/* Characters written counter */
	int			hexlen;		/* Length of hex representation */
	t_flglst	*width;		/* Width flag pointer */

	len = 0;
	hexlen = ft_hexlen(hex);
	width = ft_flgfind(flags, WIDTH);
	/* Handle standard width formatting (no precision or precision <= hexlen) */
	if (!ft_flgfind(flags, PREC)
		|| (ft_flgfind(flags, PREC) && width && !ft_flgfind(flags, ALIGN)
			&& ft_flgfind(flags, PREC)-> value <= hexlen))
	{
		/* Account for prefix length in width calculations */
		if (type == 'p' || ft_flgfind(flags, '#'))
			hexlen += 2;
		/* Space padding (right-aligned, no zero flag or precision overrides) */
		while (!ft_flgfind(flags, ALIGN)
			&& (!ft_flgfind(flags, ZERO) || ft_flgfind(flags, PREC))
			&& width && width -> value-- > hexlen)
			len += ft_putchar_fd(' ', 1, NULL);
		/* Zero padding (right-aligned with zero flag, no precision) */
		while (!ft_flgfind(flags, ALIGN) && ft_flgfind(flags, ZERO)
			&& width && width -> value-- > hexlen)
			len += ft_putchar_fd('0', 1, NULL);
	}
	else if (ft_flgfind(flags, PREC))		/* Precision formatting */
		len += ft_precision(flags);
	len += ft_putprefix(hex, type, flags);		/* Print prefix after padding */
	return (len);
}

/*
** ft_postprocflags - Apply post-processing formatting after hex digit output
** @hex: Hexadecimal value that was formatted
** @type: Format specifier type ('p', 'x', 'X')
** @flags: Formatting flags for width and alignment
**
** Handles left-aligned formatting by adding trailing spaces after the hex
** digits have been printed. Only applies when the ALIGN flag (left-alignment)
** is present. Accounts for prefix length when calculating remaining width.
** Returns the number of characters written for trailing padding.
*/
static int	ft_postprocflags(unsigned long hex, char type, t_flglst *flags)
{
	int			len;		/* Characters written counter */
	int			hexlen;		/* Length of hex representation */
	t_flglst	*width;		/* Width flag pointer */

	len = 0;
	hexlen = ft_hexlen(hex);
	width = ft_flgfind(flags, WIDTH);
	/* Account for prefix length in total width */
	if (type == 'p' || ft_flgfind(flags, '#'))
		hexlen += 2;
	/* Apply left-aligned trailing space padding */
	while (ft_flgfind(flags, ALIGN) && width && width -> value-- > hexlen)
		len += ft_putchar_fd(' ', 1, NULL);
	return (len);
}

/*
** ft_printhex - Print hexadecimal number with full printf formatting
** @hex: Unsigned long value to print in hexadecimal
** @type: Format specifier ('p' for pointer, 'x' for lowercase, 'X' for uppercase)
** @flags: Complete set of formatting flags (width, precision, alignment, etc.)
**
** Main hexadecimal printing function that orchestrates all formatting aspects.
** Handles special cases: zero values with precision, pointer null representation,
** and precision-based zero display. Coordinates preprocessing (width/padding),
** actual digit output, and postprocessing (left-alignment). Manages complex
** interactions between precision, width, and special format requirements.
** Cleans up flag list and returns total characters written.
*/
int	ft_printhex(unsigned long hex, char type, t_flglst *flags)
{
	int	len;		/* Characters written counter */
	int	lastzero;	/* Flag for precision-required trailing zero */

	len = 0;
	lastzero = 0;
	/* Check if precision requires a trailing zero for zero value */
	if (hex == 0 && ft_flgfind(flags, PREC)
		&& ft_flgfind(flags, PREC)-> value > 0)
		lastzero = 1;
	/* Handle zero value with zero precision but width specified */
	if (hex == 0 && ft_flgfind(flags, PREC)
		&& ft_flgfind(flags, PREC)-> value == 0
		&& ft_flgfind(flags, WIDTH) && ft_flgfind(flags, WIDTH)-> value != 0)
		len += ft_putchar_fd(' ', 1, NULL);
	/* Apply preprocessing formatting for non-zero or non-pointer values */
	if (hex || type != 'p')
		len += ft_preprocflags(hex, type, flags);
	/* Special case: null pointer representation */
	if (type == 'p')
		if (!hex)
			len += ft_putstr_fd("(nil)", 1, flags);
	/* Print actual hexadecimal digits */
	if (hex || type != 'p')
		len += ft_puthex_fd(hex, 1, ft_isupper(type), flags);
	/* Add trailing zero if required by precision */
	if (lastzero)
		len += ft_putchar_fd('0', 1, NULL);
	/* Apply postprocessing formatting (left-alignment) */
	if (hex || type != 'p')
		len += ft_postprocflags(hex, type, flags);
	ft_flgclear(&flags);		/* Clean up flag list */
	return (len);
}
