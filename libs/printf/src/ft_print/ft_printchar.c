/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:02:28 by acesteve          #+#    #+#             */
/*   Updated: 2025/06/16 19:39:48 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c, t_flglst *flags)
{
	int	len;

	len = ft_putchar_fd(c, 1, flags);
	ft_flgclear(&flags);
	return (len);
}
