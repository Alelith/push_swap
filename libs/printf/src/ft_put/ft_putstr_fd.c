/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:08:37 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/25 22:05:27 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd, t_flglst *flags)
{
	int			len;
	int			res;
	t_flglst	*size;
	t_flglst	*width;

	len = ft_strlen(s);
	res = 0;
	size = ft_flgfind(flags, PREC);
	width = ft_flgfind(flags, WIDTH);
	if (size && size -> value < len)
		len = size -> value;
	if (!ft_flgfind(flags, ALIGN) && width)
		while (width -> value-- > len)
			res += ft_putchar_fd(' ', fd, NULL);
	write(fd, s, len);
	if (ft_flgfind(flags, ALIGN) && width)
		while (width -> value-- > len)
			res += ft_putchar_fd(' ', fd, NULL);
	return (len + res);
}
