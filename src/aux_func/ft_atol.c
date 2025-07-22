/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:36:26 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/22 11:10:11 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *nptr)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && *nptr >= 48 && *nptr <= 57)
	{
		result = (result * 10) + (*nptr - 48);
		nptr++;
	}
	return (result * sign);
}
