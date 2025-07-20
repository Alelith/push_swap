/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:32:38 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/18 23:14:02 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_list(t_list *self)
{
	int	i;
	int	temp;

	if (!self || !(self -> length))
		return ;
	i = self -> length - 1;
	temp = self -> get(self, i);
	while (i > 0)
	{
		self -> elements[i] = self -> get(self, i - 1);
		i--;
	}
	self -> elements[i] = temp;
}
