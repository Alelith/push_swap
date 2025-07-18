/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smallest_element.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:16:56 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/17 20:22:13 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest_element(t_list *self)
{
	int	i;
	int	big;

	i = 0;
	big = 0;
	while (i < self -> length)
	{
		if (self -> get(self, i) < self -> get(self, big))
			big = i;
		i++;
	}
	return (big);
}
