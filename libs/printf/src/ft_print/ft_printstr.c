/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:15:39 by acesteve          #+#    #+#             */
/*   Updated: 2025/06/16 19:41:27 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str, t_flglst *flags)
{
	int	len;

	if (str)
		len = ft_putstr_fd(str, 1, flags);
	else if (!ft_flgfind(flags, PREC)
		|| (ft_flgfind(flags, PREC)
			&& ft_flgfind(flags, PREC)-> value >= 6))
		len = ft_putstr_fd("(null)", 1, flags);
	else
		len = ft_putstr_fd("", 1, flags);
	ft_flgclear(&flags);
	return (len);
}
