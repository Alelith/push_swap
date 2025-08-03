/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:41:37 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:20:14 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_calcexp - Calculate exponent for scientific notation
** @num: Pointer to the number to normalize (modified in place)
**
** Calculates the exponent needed to express the number in scientific notation.
** Normalizes the number to be between 1.0 and 10.0 by adjusting the exponent.
** Modifies the input number in place. Used for %e, %E, %g, %G format specifiers.
** Returns the calculated exponent value.
*/
static int	ft_calcexp(double *num)
{
	int	exp;		/* Exponent counter */

	exp = 0;
	while (*num >= 10.0)	/* Reduce numbers >= 10 */
	{
		*num /= 10;
		exp++;
	}
	while (*num > 0.0 && *num < 1.0)	/* Increase numbers < 1 */
	{
		*num *= 10;
		exp--;
	}
	return (exp);
}

/*
** ft_printdec - Print decimal/floating-point number with format type
** @num: Double value to print
** @type: Format specifier type ('f', 'e', 'E', 'g', 'G')
**
** Handles printing of floating-point numbers in various formats.
** For 'f' format, prints as fixed-point decimal. For 'e'/'E' formats,
** uses scientific notation. For 'g'/'G' formats, chooses between fixed
** and scientific based on exponent range. Returns number of characters printed.
*/
int	ft_printdec(double num, char type)
{
	int		exp;		/* Scientific notation exponent */
	int		sign;		/* Sign of the number */
	int		len;		/* Characters printed counter */
	double	tempnum;	/* Working copy of the number */

	if (type == 'f')			/* Fixed-point format */
		return (ft_putdouble_fd(num, 1));
	sign = 1;
	tempnum = num;
	if (tempnum < 1)			/* Handle negative numbers */
	{
		sign = -1;
		tempnum = -tempnum;
	}
	exp = ft_calcexp(&tempnum);		/* Calculate exponent */
	len = 0;
	/* Choose format based on type and exponent range */
	if ((type == 'g' || type == 'G') && (exp > -6 && exp < 6))
		return (ft_putdouble_fd(num, 1));	/* Use fixed format */
	else					/* Use scientific format */
	{
		len += ft_putdouble_fd(sign * tempnum, 1);
		len += ft_putexp_fd(exp, 1, ft_isupper(type));
	}
	return (len);
}
