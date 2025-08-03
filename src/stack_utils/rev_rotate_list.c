/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:32:38 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:43:15 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rev_rotate_list - Reverse rotate all elements downward (last becomes first)
** @self: Pointer to the list structure to reverse rotate
**
** Implements the core reverse rotation operation used by rra and rrb commands.
** Shifts all elements down by one position: the last element moves to
** the first position, and all other elements move one position down.
** Does nothing if the list is NULL or empty. This operation provides
** an alternative way to position elements during sorting.
*/
void	rev_rotate_list(t_list *self)
{
	int	i;		/* Loop counter */
	int	temp;		/* Temporary storage for last element */

	if (!self || !(self -> length))		/* Safety check */
		return ;
	i = self -> length - 1;
	temp = self -> get(self, i);		/* Save last element */
	
	/* Shift all elements down by one position */
	while (i > 0)
	{
		self -> elements[i] = self -> get(self, i - 1);
		i--;
	}
	self -> elements[i] = temp;		/* Place last element at beginning */
}
