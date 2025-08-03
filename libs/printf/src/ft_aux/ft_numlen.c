/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:56:21 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:10:12 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Number length calculation functions for printf formatting
**
** These functions calculate the number of digits required to represent
** various numeric values in different bases. Used for width calculation,
** padding, and precision formatting in the printf implementation.
*/

/*
** ft_intlen - Calculate the number of digits in a signed integer
** @num: Integer to measure
**
** Counts the number of digits needed to represent the integer in decimal,
** including the sign for negative numbers. Used for width calculations
** and padding in decimal format specifiers (%d, %i).
*/
int	ft_intlen(int num)
{
	int	i;		/* Digit counter */

	i = 0;
	if (num <= 0)		/* Handle negative numbers and zero */
		i++;		/* Account for sign or single zero digit */
	while (num != 0)	/* Count digits */
	{
		num /= 10;
		i++;
	}
	return (i);
}

/*
** ft_uintlen - Calculate the number of digits in an unsigned integer
** @num: Unsigned integer to measure
**
** Counts the number of digits needed to represent the unsigned integer
** in decimal. Used for width calculations in unsigned format specifiers (%u).
*/
int	ft_uintlen(unsigned int num)
{
	int	i;		/* Digit counter */

	i = 0;
	if (num == 0)		/* Special case for zero */
		i++;
	while (num != 0)	/* Count digits */
	{
		num /= 10;
		i++;
	}
	return (i);
}

/*
** ft_octlen - Calculate the number of digits in an octal number
** @num: Number to measure in octal
**
** Counts the number of octal digits needed to represent the number.
** Used for width calculations in octal format specifiers (%o).
*/
int	ft_octlen(unsigned int num)
{
	int	i;		/* Digit counter */

	i = 0;
	if (num == 0)		/* Special case for zero */
		i++;
	while (num != 0)	/* Count octal digits */
	{
		num /= 8;
		i++;
	}
	return (i);
}

/*
** ft_hexlen - Calculate the number of digits in a hexadecimal number
** @num: Number to measure in hexadecimal
**
** Counts the number of hexadecimal digits needed to represent the number.
** Used for width calculations in hexadecimal format specifiers (%x, %X, %p).
*/
int	ft_hexlen(unsigned long num)
{
	int	len;		/* Digit counter */

	len = 0;
	if (num == 0)		/* Special case for zero */
		len++;
	while (num)		/* Count hex digits */
	{
		num /= 16;
		len++;
	}
	return (len);
}
