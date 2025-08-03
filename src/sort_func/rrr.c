/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:47:07 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:34:33 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rrr - Reverse rotate both stacks A and B downward simultaneously
** @a: Pointer to stack A
** @b: Pointer to stack B
**
** Performs rra and rrb operations at the same time. Shifts all elements
** of both stacks down by one position. The last element of each stack
** becomes the first element. This is one of the allowed operations
** in the push_swap algorithm and is more efficient than separate rra and rrb.
*/
void	rrr(t_list *a, t_list *b)
{
	a -> rev_rotate(a);	/* Execute reverse rotate operation on stack A */
	b -> rev_rotate(b);	/* Execute reverse rotate operation on stack B */
	ft_printf("rrr\n");	/* Output the operation name */
}
