/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:52:19 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:43:14 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** push_element - Push the top element from one list to another
** @self: Pointer to the destination list (receives the element)
** @other: Pointer to the source list (loses the element)
**
** Implements the core push operation used by pa and pb commands.
** Takes the first element from the 'other' list and places it at
** the top (index 0) of 'self' list. All existing elements in 'self'
** are shifted down by one position. The element is removed from 'other'.
** Does nothing if either list is NULL.
*/
void	push_element(t_list *self, t_list *other)
{
	int	i;		/* Loop counter for shifting elements */

	if (!self || !other)			/* Safety check for NULL pointers */
		return ;
	resize(self, self -> length + 1);	/* Expand destination list */
	self -> length++;			/* Update length */
	i = self -> length - 1;
	
	/* Shift all existing elements down by one position */
	while (i > 0)
	{
		self -> elements[i] = self -> get(self, i - 1);
		i--;
	}
	
	/* Place new element at top of destination list */
	self -> elements[0] = other -> get(other, 0);
	other -> delete(other, 0);		/* Remove element from source list */
}
