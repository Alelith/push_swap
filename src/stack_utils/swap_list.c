/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:06:25 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/15 19:09:02 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_list *self)
{
	int	temp;

	if (!self || !(self -> length))
		return ;
	temp = self -> elements[0];
	self -> elements[0] = self -> elements[1];
	self -> elements[1] = temp;
}
