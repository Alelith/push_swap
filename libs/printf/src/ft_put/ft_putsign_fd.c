/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:30:47 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:10:15 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_putsign_fd - Print sign character based on flags and number sign
** @flags: Formatting flags that may specify sign behavior
** @fd: File descriptor to write to
** @sign: Sign of the number (positive, negative, or zero)
**
** Prints appropriate sign character based on printf flags and number sign.
** Handles '+' flag (always show sign), space flag (show space for positive),
** and automatic minus sign for negative numbers. Used in numeric formatting
** to ensure proper sign display. Returns number of characters written.
*/
int	ft_putsign_fd(t_flglst *flags, int fd, int sign)
{
	int	len;		/* Characters written counter */

	len = 0;
	if (ft_flgfind(flags, SIGN) && sign > 0)	/* '+' flag for positive */
		len += ft_putchar_fd('+', fd, NULL);
	else if (ft_flgfind(flags, SPACE) && sign > 0)	/* Space for positive */
		len += ft_putchar_fd(' ', fd, NULL);
	else if (sign < 0)				/* Minus for negative */
		len += ft_putchar_fd('-', fd, NULL);
	return (len);
}
