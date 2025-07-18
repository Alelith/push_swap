/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flgclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:01:11 by acesteve          #+#    #+#             */
/*   Updated: 2025/06/16 20:36:30 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_flgclear(t_flglst **lst)
{
	t_flglst	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)-> next;
		free (*lst);
		*lst = temp;
	}
}
