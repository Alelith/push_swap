/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smallest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:46:51 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 15:50:29 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_list *self)
{
	int	i;
	int	smallest_idx;
	int	smallest;

	i = 1;
	smallest_idx = 0;
	smallest = self -> get(self, 0);
	while (i < self -> length)
	{
		if (smallest > self -> get(self, i))
		{
			smallest_idx = i;
			smallest = self -> get(self, i);
		}
		i++;
	}
	return (smallest_idx);
}
