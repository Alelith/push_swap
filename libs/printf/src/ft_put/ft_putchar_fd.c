/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:20:42 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:04:39 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/*
** ft_putchar_fd - Write a character to file descriptor with formatting
** @c: Character to write
** @fd: File descriptor to write to
** @flags: Formatting flags for width and alignment
**
** Writes a single character to the specified file descriptor, applying
** any width and alignment formatting specified in the flags. Handles
** left and right alignment with appropriate padding. Core low-level
** function for character output in the printf implementation.
** Returns the total number of characters written (including padding).
*/
int	ft_putchar_fd(char c, int fd, t_flglst *flags)
{
	t_flglst	*width_flag;	/* Width specification flag */
	t_flglst	*align_flag;	/* Alignment flag */
	int		written;	/* Characters written counter */
	int		i;		/* Loop counter for padding */

	written = 0;
	width_flag = ft_flgfind(flags, WIDTH);	/* Find width specification */
	align_flag = ft_flgfind(flags, ALIGN);	/* Find alignment flag */
	
	/* Handle right alignment (default) - pad before character */
	if (width_flag && !align_flag)
	{
		i = 0;
		while (i < width_flag -> value - 1)	/* Add padding spaces */
		{
			write(fd, " ", 1);
			written++;
			i++;
		}
	}
	
	write(fd, &c, 1);			/* Write the actual character */
	written++;
	
	/* Handle left alignment - pad after character */
	if (width_flag && align_flag)
	{
		i = 0;
		while (i < width_flag -> value - 1)	/* Add trailing spaces */
		{
			write(fd, " ", 1);
			written++;
			i++;
		}
	}
	
	return (written);
}

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
