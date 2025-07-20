/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:37:09 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/18 23:14:02 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *self)
{
	int	i;

	i = 0;
	while (i < self -> length - 1)
	{
		if (self -> get(self, i) > self -> get(self, i + 1))
			return (0);
		i++;
	}
	return (1);
}
