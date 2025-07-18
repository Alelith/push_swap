/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:53:19 by acesteve          #+#    #+#             */
/*   Updated: 2025/06/16 19:43:58 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nbr, char type, t_flglst *flags)
{
	int	len;

	len = 0;
	if (type == 'i' || type == 'd')
		len = ft_putnbr_fd(nbr, 1, flags);
	else if (type == 'u')
		len = ft_putunbr_fd(nbr, 1, flags);
	else if (type == 'o')
		len = ft_putoct_fd(nbr, 1);
	ft_flgclear(&flags);
	return (len);
}
