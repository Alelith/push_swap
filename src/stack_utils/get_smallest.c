/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smallest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:46:51 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:43:13 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** get_smallest - Find the index of the smallest element in the list
** @self: Pointer to the list structure to search
**
** Iterates through the entire list to find the element with the smallest
** value and returns its index. This is used in the final phase of sorting
** to position the smallest element at the top of stack A. Essential for
** completing the sorting process.
**
** Return: Index of the smallest element (0-based)
*/
int	get_smallest(t_list *self)
{
	int	i;		/* Loop counter */
	int	smallest_idx;	/* Index of smallest element found */
	int	smallest;	/* Value of smallest element found */

	i = 1;
	smallest_idx = 0;			/* Start with first element */
	smallest = self -> get(self, 0);	/* Get first element value */
	while (i < self -> length)
	{
		if (smallest > self -> get(self, i))	/* Found smaller element */
		{
			smallest_idx = i;		/* Update index */
			smallest = self -> get(self, i);	/* Update value */
		}
		i++;
	}
	return (smallest_idx);			/* Return index of smallest */
}
