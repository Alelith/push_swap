/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:00:12 by acesteve          #+#    #+#             */
/*   Updated: 2025/06/16 20:35:49 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putprefix(unsigned long hex, char type, t_flglst *flags)
{
	int	len;

	len = 0;
	if ((type == 'p' || ft_flgfind(flags, '#')) && hex)
	{
		if (type == 'p' && hex)
			len += ft_putstr_fd("0x", 1, NULL);
		else if (!ft_isupper(type) && type != 'p')
			len += ft_putstr_fd("0x", 1, NULL);
		else if (ft_isupper(type))
			len += ft_putstr_fd("0X", 1, NULL);
	}
	return (len);
}

static int	ft_precision(t_flglst *flags)
{
	int			len;
	t_flglst	*width;

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	while (!ft_flgfind(flags, ALIGN)
		&& width && width -> value > ft_flgfind(flags, PREC)-> value)
	{
		len += ft_putchar_fd(' ', 1, NULL);
		width -> value--;
	}
	return (len);
}

static int	ft_preprocflags(unsigned long hex, char type, t_flglst *flags)
{
	int			len;
	int			hexlen;
	t_flglst	*width;

	len = 0;
	hexlen = ft_hexlen(hex);
	width = ft_flgfind(flags, WIDTH);
	if (!ft_flgfind(flags, PREC)
		|| (ft_flgfind(flags, PREC) && width && !ft_flgfind(flags, ALIGN)
			&& ft_flgfind(flags, PREC)-> value <= hexlen))
	{
		if (type == 'p' || ft_flgfind(flags, '#'))
			hexlen += 2;
		while (!ft_flgfind(flags, ALIGN)
			&& (!ft_flgfind(flags, ZERO) || ft_flgfind(flags, PREC))
			&& width && width -> value-- > hexlen)
			len += ft_putchar_fd(' ', 1, NULL);
		while (!ft_flgfind(flags, ALIGN) && ft_flgfind(flags, ZERO)
			&& width && width -> value-- > hexlen)
			len += ft_putchar_fd('0', 1, NULL);
	}
	else if (ft_flgfind(flags, PREC))
		len += ft_precision(flags);
	len += ft_putprefix(hex, type, flags);
	return (len);
}

static int	ft_postprocflags(unsigned long hex, char type, t_flglst *flags)
{
	int			len;
	int			hexlen;
	t_flglst	*width;

	len = 0;
	hexlen = ft_hexlen(hex);
	width = ft_flgfind(flags, WIDTH);
	if (type == 'p' || ft_flgfind(flags, '#'))
		hexlen += 2;
	while (ft_flgfind(flags, ALIGN) && width && width -> value-- > hexlen)
		len += ft_putchar_fd(' ', 1, NULL);
	return (len);
}

int	ft_printhex(unsigned long hex, char type, t_flglst *flags)
{
	int	len;
	int	lastzero;

	len = 0;
	lastzero = 0;
	if (hex == 0 && ft_flgfind(flags, PREC)
		&& ft_flgfind(flags, PREC)-> value > 0)
		lastzero = 1;
	if (hex == 0 && ft_flgfind(flags, PREC)
		&& ft_flgfind(flags, PREC)-> value == 0
		&& ft_flgfind(flags, WIDTH) && ft_flgfind(flags, WIDTH)-> value != 0)
		len += ft_putchar_fd(' ', 1, NULL);
	if (hex || type != 'p')
		len += ft_preprocflags(hex, type, flags);
	if (type == 'p')
		if (!hex)
			len += ft_putstr_fd("(nil)", 1, flags);
	if (hex || type != 'p')
		len += ft_puthex_fd(hex, 1, ft_isupper(type), flags);
	if (lastzero)
		len += ft_putchar_fd('0', 1, NULL);
	if (hex || type != 'p')
		len += ft_postprocflags(hex, type, flags);
	ft_flgclear(&flags);
	return (len);
}
