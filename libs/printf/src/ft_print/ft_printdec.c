/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:41:37 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/23 22:37:55 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calcexp(double *num)
{
	int	exp;

	exp = 0;
	while (*num >= 10.0)
	{
		*num /= 10;
		exp++;
	}
	while (*num > 0.0 && *num < 1.0)
	{
		*num *= 10;
		exp--;
	}
	return (exp);
}

int	ft_printdec(double num, char type)
{
	int		exp;
	int		sign;
	int		len;
	double	tempnum;

	if (type == 'f')
		return (ft_putdouble_fd(num, 1));
	sign = 1;
	tempnum = num;
	if (tempnum < 1)
	{
		sign = -1;
		tempnum = -tempnum;
	}
	exp = ft_calcexp(&tempnum);
	len = 0;
	if ((type == 'g' || type == 'G') && (exp > -6 && exp < 6))
		return (ft_putdouble_fd(num, 1));
	else
	{
		len += ft_putdouble_fd(sign * tempnum, 1);
		len += ft_putexp_fd(exp, 1, ft_isupper(type));
	}
	return (len);
}
