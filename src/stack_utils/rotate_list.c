/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:12:23 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:43:14 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rotate_list - Rotate all elements upward (first becomes last)
** @self: Pointer to the list structure to rotate
**
** Implements the core rotation operation used by ra and rb commands.
** Shifts all elements up by one position: the first element moves to
** the last position, and all other elements move one position up.
** Does nothing if the list is NULL or empty. This operation is crucial
** for positioning elements optimally during the sorting process.
*/
void	rotate_list(t_list *self)
{
	int	i;		/* Loop counter */
	int	temp;		/* Temporary storage for first element */

	if (!self || !(self -> length))		/* Safety check */
		return ;
	i = 0;
	temp = self -> get(self, 0);		/* Save first element */
	
	/* Shift all elements up by one position */
	while (i < self -> length - 1)
	{
		self -> elements[i] = self -> get(self, i + 1);
		i++;
	}
	self -> elements[i] = temp;		/* Place first element at end */
}
