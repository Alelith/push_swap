/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:36:26 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:18 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_atol - Convert string to long integer
** @nptr: Pointer to the string to convert
**
** Converts the initial portion of the string pointed to by nptr to a long
** integer. Handles optional leading '+' or '-' signs and processes digits
** until a non-digit character is encountered.
**
** Return: The converted long integer value
*/
long	ft_atol(const char *nptr)
{
	long	sign;		/* Sign multiplier (1 or -1) */
	long	result;		/* Accumulated result */

	sign = 1;
	result = 0;
	
	/* Handle negative sign */
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	/* Handle positive sign (optional) */
	else if (*nptr == '+')
		nptr++;
	
	/* Convert digits to long integer */
	while (*nptr && *nptr >= 48 && *nptr <= 57)	/* ASCII '0' to '9' */
	{
		result = (result * 10) + (*nptr - 48);	/* Shift and add digit */
		nptr++;
	}
	return (result * sign);
}
