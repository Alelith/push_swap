/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:15:41 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:10:13 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlen - Calculate the length of a string
** @s: String to measure
**
** Counts the number of characters in the string up to (but not including)
** the null terminator. Used throughout the printf implementation for
** calculating string widths, padding requirements, and buffer management.
** Returns the length as an unsigned long.
*/
unsigned long	ft_strlen(const char *s)
{
	unsigned long	i;	/* Character counter */

	i = 0;
	while (s[i])		/* Count characters until null terminator */
		i++;
	return (i);
}
