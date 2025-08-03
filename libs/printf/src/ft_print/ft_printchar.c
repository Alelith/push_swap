/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:02:28 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:03:44 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_printchar - Print a character with format flags
** @c: Character to print
** @flags: Linked list of formatting flags
**
** Prints a single character applying any relevant formatting flags
** (such as field width and alignment). Delegates to ft_putchar_fd
** for the actual output with flag processing. Cleans up the flag
** list after printing. Returns the number of characters printed.
*/
int	ft_printchar(char c, t_flglst *flags)
{
	int	len;		/* Number of characters printed */

	len = ft_putchar_fd(c, 1, flags);	/* Print with flag processing */
	ft_flgclear(&flags);			/* Clean up flag list */
	return (len);
}
