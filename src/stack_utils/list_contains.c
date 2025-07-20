/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_contains.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:40:24 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/19 17:52:42 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_contains(t_list *self, int num)
{
	int	i;

	i = 0;
	while (i < self -> length)
	{
		if (num == self -> get(self, i))
			return (1);
		i++;
	}
	return (0);
}
