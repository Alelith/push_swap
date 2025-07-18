/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:56:21 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/25 23:02:14 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_uintlen(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_octlen(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		i++;
	while (num != 0)
	{
		num /= 8;
		i++;
	}
	return (i);
}

int	ft_hexlen(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		len++;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}
