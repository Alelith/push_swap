/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:06:31 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/25 22:05:27 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar_fd(char c, int fd, t_flglst *flags)
{
	int			len;
	t_flglst	*width;

	len = 0;
	width = ft_flgfind(flags, WIDTH);
	while (!ft_flgfind(flags, ALIGN) && width && --(width -> value))
		len += ft_putchar_fd(' ', fd, NULL);
	write(fd, &c, 1);
	while (ft_flgfind(flags, ALIGN) && width && --(width -> value))
		len += ft_putchar_fd(' ', fd, NULL);
	len++;
	return (len);
}
