/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:34:36 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:46:43 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** delete_element - Remove an element at the specified index from the list
** @self: Pointer to the list structure
** @index: Index of the element to remove (0-based)
**
** Removes the element at the given index and shifts all subsequent elements
** one position to the left to fill the gap. Resizes the list to reflect
** the new smaller size and decrements the length. Performs bounds checking
** and exits with error if the index is invalid. This is used primarily
** during push operations when elements are moved between stacks.
*/
void	delete_element(t_list *self, int index)
{
	int	i;		/* Loop counter for shifting elements */

	if (index < 0 || index >= self -> length)		/* Bounds check */
	{
		ft_printf("Index out of range");		/* Error message */
		self -> clean(self);				/* Clean up memory */
		exit(EXIT_FAILURE);				/* Exit safely */
	}
	i = index;
	
	/* Shift all elements after the deleted index one position left */
	while (i < self -> length - 1)
	{
		self -> elements[i] = self -> elements[i + 1];
		i++;
	}
	resize(self, self -> length - 1);			/* Shrink the list */
	self -> length--;					/* Decrement length counter */
}
