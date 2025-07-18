/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsign_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:30:47 by acesteve          #+#    #+#             */
/*   Updated: 2025/06/16 21:33:48 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putsign_fd(t_flglst *flags, int fd, int sign)
{
	int	len;

	len = 0;
	if (ft_flgfind(flags, SIGN) && sign > 0)
		len += ft_putchar_fd('+', fd, NULL);
	else if (ft_flgfind(flags, SPACE) && sign > 0)
		len += ft_putchar_fd(' ', fd, NULL);
	else if (sign < 0)
		len += ft_putchar_fd('-', fd, NULL);
	return (len);
}
