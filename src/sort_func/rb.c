/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:45:20 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:30:10 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rb - Rotate stack B upward
** @b: Pointer to stack B
**
** Shifts all elements of stack B up by one position. The first element
** becomes the last element. Does nothing if the stack has less than 2 elements.
** This is one of the allowed operations in the push_swap algorithm.
*/
void	rb(t_list *b)
{
	b -> rotate(b);		/* Execute the rotate operation */
	ft_printf("rb\n");	/* Output the operation name */
}
