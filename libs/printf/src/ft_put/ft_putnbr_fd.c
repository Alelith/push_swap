/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:21:16 by acesteve          #+#    #+#             */
/*   Updated: 2025/06/16 21:35:15 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_applyprecision(int n, int fd, t_flglst *flags, int sign)
{
	int			len;
	t_flglst	*width;
	t_flglst	*prec;

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	prec = ft_flgfind(flags, PREC);
	while (width && !ft_flgfind(flags, ALIGN)
		&& ((sign > 0 && width -> value-- > prec -> value)
			|| (sign < 0 && width -> value-- > prec -> value + 1)))
		len += ft_putchar_fd(' ', fd, NULL);
	len += ft_putsign_fd(flags, fd, sign);
	while ((!width && prec -> value-- > ft_intlen(n))
		|| (width && !ft_flgfind(flags, ALIGN)
			&& prec -> value-- > ft_intlen(n)))
		len += ft_putchar_fd('0', fd, NULL);
	while (ft_flgfind(flags, ALIGN) && width -> value--
		&& prec -> value-- > ft_intlen(n))
		len += ft_putchar_fd('0', fd, NULL);
	while (ft_flgfind(flags, ALIGN)
		&& prec -> value-- > ft_intlen(n))
		len += ft_putchar_fd('0', fd, NULL);
	return (len);
}

static int	ft_precision(int n, int fd, t_flglst *flags, int sign)
{
	int			len;
	t_flglst	*width;

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	if (ft_flgfind(flags, PREC)-> value >= ft_intlen(n))
	{
		len += ft_applyprecision(n, fd, flags, sign);
		if (n == 0)
			len += ft_putchar_fd('0' + (n % 10), fd, NULL);
	}
	else
	{
		while (!ft_flgfind(flags, ALIGN)
			&& width && width -> value-- > ft_intlen(n * sign))
			len += ft_putchar_fd(' ', fd, NULL);
		if (sign < 0)
			len += ft_putchar_fd('-', fd, NULL);
		if (ft_flgfind(flags, ALIGN))
			width -> value--;
		if (n == 0 && width)
			len += ft_putchar_fd(' ', fd, NULL);
	}
	return (len);
}

static int	ft_preprocflags(int n, int fd, t_flglst *flags, int sign)
{
	int			len;
	t_flglst	*width;

	len = 0;
	width = ft_flgfind(flags, 0);
	if (width && (ft_flgfind(flags, SIGN) || ft_flgfind(flags, SPACE)) && n > 0)
		width -> value--;
	if (!ft_flgfind(flags, PREC))
	{
		while (!ft_flgfind(flags, ALIGN) && !ft_flgfind(flags, ZERO)
			&& width && width -> value-- > ft_intlen(n * sign))
			len += ft_putchar_fd(' ', fd, NULL);
		len += ft_putsign_fd(flags, fd, sign);
		while (!ft_flgfind(flags, ALIGN) && ft_flgfind(flags, ZERO)
			&& width && width -> value-- > ft_intlen(n * sign))
			len += ft_putchar_fd('0', fd, NULL);
	}
	else
		len += ft_precision(n, fd, flags, sign);
	return (len);
}

static int	ft_postprocflags(int n, int fd, t_flglst *flags, int sign)
{
	int			len;
	t_flglst	*width;

	len = 0;
	width = ft_flgfind(flags, 0);
	if (ft_flgfind(flags, PREC) && width)
		width -> value++;
	while (ft_flgfind(flags, ALIGN) && width
		&& width -> value-- > ft_intlen(n * sign))
		len += ft_putchar_fd(' ', fd, NULL);
	return (len);
}

int	ft_putnbr_fd(int n, int fd, t_flglst *flags)
{
	int	len;
	int	sign;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd, NULL));
	len = 0;
	sign = 1;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	len += ft_preprocflags(n, fd, flags, sign);
	if (n > 9)
		len += ft_putnbr_fd(n / 10, fd, NULL);
	if (n != 0 || !ft_flgfind(flags, PREC))
		len += ft_putchar_fd('0' + (n % 10), fd, NULL);
	len += ft_postprocflags(n, fd, flags, sign);
	return (len);
}
