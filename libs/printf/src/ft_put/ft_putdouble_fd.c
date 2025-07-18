/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:23:45 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/23 22:36:04 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdouble_fd(double d, int fd)
{
	int	len;
	int	intpart;
	int	decimals;

	len = 0;
	intpart = (int) d;
	decimals = 5;
	d = d - intpart;
	if (d < 0)
		d = -d;
	len += ft_putnbr_fd(intpart, fd, NULL);
	len += ft_putchar_fd('.', fd, NULL);
	while (decimals--)
	{
		d *= 10;
		len += ft_putchar_fd(((int)d % 10) + '0', fd, NULL);
	}
	d *= 10;
	if (d - (int)d >= 0.5)
		len += ft_putchar_fd(((int)d % 10) + 1 + '0', fd, NULL);
	else
		len += ft_putchar_fd(((int)d % 10) + '0', fd, NULL);
	return (len);
}
