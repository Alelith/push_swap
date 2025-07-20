/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:52:19 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/19 23:09:41 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_element(t_list *self, t_list *other)
{
	int	i;

	if (!self || !other)
		return ;
	resize(self, self -> length + 1);
	self -> length++;
	i = self -> length - 1;
	while (i > 0)
	{
		self -> elements[i] = self -> get(self, i - 1);
		i--;
	}
	self -> elements[0] = other -> get(other, 0);
	other -> delete(other, 0);
}
