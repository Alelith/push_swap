/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flgfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:11:44 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/25 22:05:27 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flglst	*ft_flgfind(t_flglst *lst, t_flgtype type)
{
	while (lst)
	{
		if (lst -> type == type)
			return (lst);
		lst = lst -> next;
	}
	return (NULL);
}
