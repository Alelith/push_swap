/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putexp_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:02:40 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/13 22:32:47 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putexp_fd(int e, int fd, int upp)
{
	int	len;

	len = 0;
	if (upp)
		len += ft_putchar_fd('E', fd, NULL);
	else
		len += ft_putchar_fd('e', fd, NULL);
	if (e < 0)
	{
		len = ft_putchar_fd('-', fd, NULL);
		e = -e;
	}
	else
		len = ft_putchar_fd('+', fd, NULL);
	len += ft_putnbr_fd(e, fd, NULL);
	return (len);
}
