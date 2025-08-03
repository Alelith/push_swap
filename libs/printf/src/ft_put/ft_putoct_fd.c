/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoct_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:33:22 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:10:14 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_putoct_fd - Print unsigned integer in octal format to file descriptor
** @n: Unsigned integer to print in octal
** @fd: File descriptor to write to
**
** Recursively converts and prints an unsigned integer in octal (base 8) format.
** Uses recursive division by 8 to extract digits from most significant to
** least significant. Used for the %o format specifier in printf.
** Returns the total number of characters written.
*/
int	ft_putoct_fd(unsigned int n, int fd)
{
	int	len;		/* Characters written counter */

	len = 0;
	if (n > 7)		/* Recursively handle higher digits */
		len += ft_putoct_fd(n / 8, fd);
	/* Print current digit (remainder) */
	len += ft_putchar_fd('0' + (n % 8), fd, NULL);
	return (len);
}
