/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:08:37 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:27:47 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/*
** ft_putstr_fd - Write string to file descriptor with printf formatting
** @s: String to write
** @fd: File descriptor to write to
** @flags: Formatting flags for width, precision, and alignment
**
** Writes a string to the specified file descriptor with printf-style formatting.
** Handles precision (maximum characters to print), width (minimum field width),
** and alignment (left vs right justification). Precision limits the number of
** characters printed from the string. Width adds padding with spaces to reach
** the minimum field width. Right-aligned by default, left-aligned with ALIGN flag.
** Returns the total number of characters written (including padding).
*/
int	ft_putstr_fd(char *s, int fd, t_flglst *flags)
{
	int			len;		/* Effective string length to print */
	int			res;		/* Padding characters written */
	t_flglst	*size;		/* Precision flag pointer */
	t_flglst	*width;		/* Width flag pointer */

	len = ft_strlen(s);			/* Get full string length */
	res = 0;
	size = ft_flgfind(flags, PREC);		/* Find precision specification */
	width = ft_flgfind(flags, WIDTH);	/* Find width specification */
	/* Apply precision limit if specified and smaller than string length */
	if (size && size -> value < len)
		len = size -> value;
	/* Right-aligned: add leading spaces before string */
	if (!ft_flgfind(flags, ALIGN) && width)
		while (width -> value-- > len)
			res += ft_putchar_fd(' ', fd, NULL);
	write(fd, s, len);			/* Write the actual string content */
	/* Left-aligned: add trailing spaces after string */
	if (ft_flgfind(flags, ALIGN) && width)
		while (width -> value-- > len)
			res += ft_putchar_fd(' ', fd, NULL);
	return (len + res);			/* Return total characters written */
}
