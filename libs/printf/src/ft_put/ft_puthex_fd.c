/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:47:21 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/27 11:46:15 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_applyprecision(unsigned long n, int fd, t_flglst *flags)
{
	int			len;
	t_flglst	*width;
	t_flglst	*prec;

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	prec = ft_flgfind(flags, PREC);
	while (width && !ft_flgfind(flags, ALIGN)
		&& width -> value-- > prec -> value)
		len += ft_putchar_fd(' ', fd, NULL);
	while ((!width && prec -> value-- > ft_hexlen(n))
		|| (width && !ft_flgfind(flags, ALIGN)
			&& prec -> value-- > ft_hexlen(n)))
		len += ft_putchar_fd('0', fd, NULL);
	while (ft_flgfind(flags, ALIGN)
		&& prec -> value-- > ft_hexlen(n))
	{
		len += ft_putchar_fd('0', fd, NULL);
		if (width -> value)
			width -> value--;
	}
	return (len);
}

static int	ft_precision(unsigned long n, int fd, t_flglst *flags)
{
	int			len;
	t_flglst	*prec;
	t_flglst	*width;

	len = 0;
	prec = ft_flgfind(flags, PREC);
	width = ft_flgfind(flags, WIDTH);
	if (prec -> value >= ft_hexlen(n))
		len += ft_applyprecision(n, fd, flags);
	else
	{
		while (!ft_flgfind(flags, ALIGN)
			&& width && width -> value-- > ft_hexlen(n))
			len += ft_putchar_fd(' ', fd, NULL);
		if (ft_flgfind(flags, ALIGN) && width -> value < prec -> value)
			width -> value--;
	}
	return (len);
}

static int	ft_preprocflags(unsigned long n, int fd, t_flglst *flags)
{
	int	len;

	len = 0;
	if (ft_flgfind(flags, PREC))
		len += ft_precision(n, fd, flags);
	return (len);
}

int	ft_puthex_fd(unsigned long p, int fd, int upp, t_flglst *flags)
{
	int				len;
	char			*hex;

	len = 0;
	if (!upp)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	len += ft_preprocflags(p, fd, flags);
	if (p > 15)
		len += ft_puthex_fd(p / 16, fd, upp, NULL);
	if (p > 0 || !ft_flgfind(flags, PREC))
		len += ft_putchar_fd(hex[p % 16], fd, NULL);
	return (len);
}
