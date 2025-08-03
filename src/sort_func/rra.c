/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:47:02 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:34:32 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rra - Reverse rotate stack A downward
** @a: Pointer to stack A
**
** Shifts all elements of stack A down by one position. The last element
** becomes the first element. Does nothing if the stack has less than 2 elements.
** This is one of the allowed operations in the push_swap algorithm.
*/
void	rra(t_list *a)
{
	a -> rev_rotate(a);	/* Execute the reverse rotate operation */
	ft_printf("rra\n");	/* Output the operation name */
}
