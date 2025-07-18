/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoct_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:33:22 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/26 13:46:25 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putoct_fd(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n > 7)
		len += ft_putoct_fd(n / 8, fd);
	len += ft_putchar_fd('0' + (n % 8), fd, NULL);
	return (len);
}
