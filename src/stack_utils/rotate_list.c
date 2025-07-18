/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:12:23 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/17 15:45:45 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_list(t_list *self)
{
	int	i;
	int	temp;

	if (!self || !(self -> length))
		return ;
	i = 0;
	temp = self -> get(self, 0);
	while (i < self -> length - 1)
	{
		self -> elements[i] = self -> get(self, i + 1);
		i++;
	}
	self -> elements[i] = temp;
}
