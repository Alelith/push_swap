/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:15:41 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:28 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlen - Calculate the length of a string
** @s: String to measure
**
** Calculates the length of the string pointed to by s, excluding
** the terminating null byte ('\0').
**
** Return: Number of characters in the string
*/
unsigned long	ft_strlen(const char *s)
{
	unsigned long	i;	/* Character counter */

	i = 0;
	while (s[i])		/* Count characters until null terminator */
		i++;
	return (i);
}
