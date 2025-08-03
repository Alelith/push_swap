/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:36:26 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:03:28 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_atoi - Convert string to integer and advance pointer
** @nptr: Pointer to string pointer to convert and advance
**
** Converts a sequence of digits at the current string position to an integer.
** Advances the string pointer past all processed digits. Used specifically
** for parsing numeric values in printf format specifiers (width, precision).
** Returns the converted integer value.
*/
int	ft_atoi(const char **nptr)
{
	int	sign;		/* Sign multiplier (unused but kept for consistency) */
	int	result;		/* Accumulated numeric result */

	sign = 1;
	result = 0;
	/* Process consecutive digits and advance pointer */
	while (**nptr && **nptr >= 48 && **nptr <= 57)
	{
		result = (result * 10) + (**nptr - 48);	/* Convert ASCII to digit */
		(*nptr)++;					/* Advance pointer */
	}
	return (result * sign);
}
