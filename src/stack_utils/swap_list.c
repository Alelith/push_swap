/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:06:25 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:48:35 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** swap_list - Swap the first two elements at the top of the list
** @self: Pointer to the list structure to swap
**
** Implements the core swap operation used by sa and sb commands.
** Exchanges the positions of the first two elements in the list.
** Does nothing if the list is NULL or has less than 2 elements.
** This operation is fundamental for fine-tuning element positions
** during the sorting process and often used in combination with
** other operations to achieve optimal sorting efficiency.
*/
void	swap_list(t_list *self)
{
	int	temp;		/* Temporary storage for first element */

	if (!self || !(self -> length))		/* Safety check */
		return ;
	temp = self -> elements[0];		/* Save first element */
	self -> elements[0] = self -> elements[1];	/* Move second to first */
	self -> elements[1] = temp;		/* Place saved element in second */
}
