/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:34:36 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/18 23:14:02 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_element(t_list *self, int index)
{
	int	i;

	if (index < 0 || index >= self -> length)
	{
		ft_printf("Index out of range");
		self -> clean(self);
		exit(EXIT_FAILURE);
	}
	i = index;
	while (i < self -> length - 1)
	{
		self -> elements[i] = self -> elements[i + 1];
		i++;
	}
	resize(self, self -> length - 1);
	self -> length--;
}
