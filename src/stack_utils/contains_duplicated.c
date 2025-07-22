/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_duplicated.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:44:22 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 19:56:28 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_duplicated(t_list *self)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < self -> length)
	{
		j = i + 1;
		temp = self -> get(self, i);
		while (j < self -> length)
		{
			if (temp == self -> get(self, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
