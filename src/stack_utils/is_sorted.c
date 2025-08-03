/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:37:09 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:43:12 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** is_sorted - Check if the list is sorted in ascending order
** @self: Pointer to the list structure to check
**
** Verifies that all elements in the list are arranged in ascending order.
** Compares each element with the next one to ensure no element is greater
** than its successor. This is used to determine when the sorting algorithm
** has completed successfully.
**
** Return: 1 if the list is sorted, 0 if not sorted
*/
int	is_sorted(t_list *self)
{
	int	i;		/* Loop counter */

	i = 0;
	while (i < self -> length - 1)			/* Check all adjacent pairs */
	{
		if (self -> get(self, i) > self -> get(self, i + 1))	/* Found disorder */
			return (0);
		i++;
	}
	return (1);					/* All elements in order */
}
