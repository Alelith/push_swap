/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:47:04 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:34:32 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rrb - Reverse rotate stack B downward
** @b: Pointer to stack B
**
** Shifts all elements of stack B down by one position. The last element
** becomes the first element. Does nothing if the stack has less than 2 elements.
** This is one of the allowed operations in the push_swap algorithm.
*/
void	rrb(t_list *b)
{
	b -> rev_rotate(b);	/* Execute the reverse rotate operation */
	ft_printf("rrb\n");	/* Output the operation name */
}
