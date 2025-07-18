/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flggadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:29:41 by acesteve          #+#    #+#             */
/*   Updated: 2025/05/25 22:06:52 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flgadd_front(t_flglst **lst, t_flglst *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}
