/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:53:15 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:27 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ft_strlcpy - Copy string with size limitation
** @dst: Destination buffer
** @src: Source string to copy
** @size: Size of the destination buffer
**
** Copies up to size-1 characters from src to dst, guaranteeing null-termination
** if size is greater than 0. This function is designed to be safer than strcpy
** by preventing buffer overflows.
**
** Return: Length of the source string (for truncation detection)
*/
unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long size)
{
	unsigned long	i;	/* Index for copying characters */

	i = 0;
	if (size != 0)
	{
		/* Copy characters up to size-1 */
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';		/* Null-terminate the destination */
	}
	return (ft_strlen(src));	/* Return length of source for truncation check */
}
