/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:13:05 by acesteve          #+#    #+#             */
/*   Updated: 2025/06/16 20:45:23 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_isvalidformat(const char *s)
{
	if (*s != '%')
		return (0);
	while (ft_isflag(*s))
		s++;
	while (ft_isdigit(*s))
		s++;
	if (*s == '.')
	{
		s++;
		if (!ft_isdigit(*s))
			return (0);
		while (ft_isdigit(*s))
			s++;
	}
	if (!ft_isspecifier(*s))
		return (0);
	return (1);
}

static void	ft_proccessflg(t_flglst **lst, const char **format)
{
	int	value;

	if (ft_isflag(**format))
	{
		if (!ft_flgfind(*lst, **format))
			ft_flgadd_back(lst, ft_flgnew(**format, 0));
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		value = ft_atoi(format);
		if (value > 0)
			ft_flgadd_back(lst, ft_flgnew(WIDTH, value));
	}
	else if (**format == '.')
	{
		(*format)++;
		value = ft_atoi(format);
		ft_flgadd_back(lst, ft_flgnew(PREC, value));
	}
}

static char	ft_proccessall(const char **format, t_flglst **flags)
{
	while (ft_isflag(**format) || ft_isdigit(**format) || **format == '.')
		ft_proccessflg(flags, format);
	return (**format);
}

static int	ft_print(va_list vargs, const char **format)
{
	char			type;
	t_flglst		*modifiers;

	modifiers = NULL;
	(*format)++;
	type = ft_proccessall(format, &modifiers);
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
	ft_flgclear(&modifiers);
	return (ft_printchar('%', NULL));
}

int	ft_printf(char const *str, ...)
{
	int		length;
	va_list	vargs;

	length = 0;
	va_start(vargs, str);
	while (str && *str)
	{
		if (*str != '%' || !ft_isvalidformat(str))
			length += ft_putchar_fd(*str, 1, NULL);
		else
			length += ft_print(vargs, &str);
		str++;
	}
	va_end(vargs);
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
