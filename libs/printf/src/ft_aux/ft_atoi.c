/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:36:26 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/13 11:16:57 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char **nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (**nptr && **nptr >= 48 && **nptr <= 57)
	{
		result = (result * 10) + (**nptr - 48);
		(*nptr)++;
	}
	return (result * sign);
}
