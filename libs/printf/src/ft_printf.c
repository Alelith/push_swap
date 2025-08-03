/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:13:05 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:03:26 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_printf.c - Main implementation of custom printf function
**
** This file contains the core logic for parsing format strings and
** dispatching to appropriate printing functions. It handles format
** validation, flag processing, and argument type detection.
*/

#include "ft_printf.h"
#include <stdarg.h>

/*
** ft_isvalidformat - Validate a printf format specifier
** @s: Pointer to the format string starting with '%'
**
** Checks if a format specifier follows valid printf syntax:
** %[flags][width][.precision]specifier
** Returns 1 if valid, 0 if invalid.
*/
static int	ft_isvalidformat(const char *s)
{
	if (*s != '%')				/* Must start with % */
		return (0);
	while (ft_isflag(*s))			/* Skip flags */
		s++;
	while (ft_isdigit(*s))			/* Skip width */
		s++;
	if (*s == '.')				/* Handle precision */
	{
		s++;
		if (!ft_isdigit(*s))		/* Precision must have digits */
			return (0);
		while (ft_isdigit(*s))
			s++;
	}
	if (!ft_isspecifier(*s))		/* Must end with valid specifier */
		return (0);
	return (1);
}

/*
** ft_proccessflg - Process a single flag from the format string
** @lst: Pointer to the flag list
** @format: Pointer to the current position in format string
**
** Parses and adds a single flag (like -, +, 0, etc.) or numeric
** values (width, precision) to the flag list. Advances the format
** pointer past the processed element.
*/
static void	ft_proccessflg(t_flglst **lst, const char **format)
{
	int	value;		/* Temporary storage for numeric values */

	if (ft_isflag(**format))		/* Handle flag characters */
	{
		if (!ft_flgfind(*lst, **format))	/* Avoid duplicates */
			ft_flgadd_back(lst, ft_flgnew(**format, 0));
		(*format)++;
	}
	else if (ft_isdigit(**format))		/* Handle width specification */
	{
		value = ft_atoi(format);
		if (value > 0)			/* Only positive widths */
			ft_flgadd_back(lst, ft_flgnew(WIDTH, value));
	}
	else if (**format == '.')		/* Handle precision specification */
	{
		(*format)++;
		value = ft_atoi(format);
		ft_flgadd_back(lst, ft_flgnew(PREC, value));
	}
}

/*
** ft_proccessall - Process all flags and modifiers in a format specifier
** @format: Pointer to the current position in format string
** @flags: Pointer to the flag list to populate
**
** Iterates through the format string, processing all flags, width,
** and precision specifiers until reaching the type specifier.
** Returns the type specifier character.
*/
static char	ft_proccessall(const char **format, t_flglst **flags)
{
	while (ft_isflag(**format) || ft_isdigit(**format) || **format == '.')
		ft_proccessflg(flags, format);
	return (**format);		/* Return the type specifier */
}

/*
** ft_print - Process a single format specifier and print the argument
** @vargs: Variable argument list
** @format: Pointer to the current position in format string
**
** Parses the complete format specifier (flags + type) and dispatches
** to the appropriate printing function based on the type specifier.
** Returns the number of characters printed.
*/
static int	ft_print(va_list vargs, const char **format)
{
	char			type;		/* Format specifier type */
	t_flglst		*modifiers;	/* List of formatting flags */

	modifiers = NULL;
	(*format)++;				/* Skip the '%' */
	type = ft_proccessall(format, &modifiers);	/* Parse flags and get type */
	
	/* Dispatch to appropriate printing function based on type */
	if (type == 'c')
		return (ft_printchar(va_arg(vargs, int), modifiers));
	else if (type == 's')
		return (ft_printstr(va_arg(vargs, char *), modifiers));
	else if (type == 'd' || type == 'i'
		|| type == 'o' || type == 'u')
		return (ft_printnbr(va_arg(vargs, int), type, modifiers));
	else if (type == 'p')
		return (ft_printhex(va_arg(vargs, unsigned long), type, modifiers));
	else if (type == 'x' || type == 'X')
		return (ft_printhex(va_arg(vargs, unsigned int), type, modifiers));
	else if (type == 'f' || type == 'e'
		|| type == 'E' || type == 'g'
		|| type == 'G')
		return (ft_printdec(va_arg(vargs, double), type));
	ft_flgclear(&modifiers);		/* Clean up flag list */
	return (ft_printchar('%', NULL));	/* Default: print literal % */
}

/*
** ft_printf - Main printf function implementation
** @str: Format string containing text and format specifiers
** @...: Variable arguments corresponding to format specifiers
**
** Custom implementation of printf that supports standard format specifiers
** and flags. Parses the format string character by character, printing
** literal characters directly and processing format specifiers through
** the ft_print function. Returns the total number of characters printed.
*/
int	ft_printf(char const *str, ...)
{
	int		length;		/* Total characters printed */
	va_list	vargs;		/* Variable argument list */

	length = 0;
	va_start(vargs, str);		/* Initialize argument processing */
	while (str && *str)		/* Process each character */
	{
		/* Print literal characters or invalid format specifiers */
		if (*str != '%' || !ft_isvalidformat(str))
			length += ft_putchar_fd(*str, 1, NULL);
		else
			length += ft_print(vargs, &str);	/* Process format specifier */
		str++;
	}
	va_end(vargs);			/* Clean up argument processing */
	return (length);
}
/*
int	main(void)
{
	char	*s;
	char	*n;

	s = " %-2c ";
	n = "a %#.3x a\n";
	printf("A: %i\t", printf(n, 0)); //-2147483648, 2147483647
	printf("B: %i\t", ft_printf(n, 0));
}*/
