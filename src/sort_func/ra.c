/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:44:50 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:29:12 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ra - Rotate stack A upward
** @a: Pointer to stack A
**
** Shifts all elements of stack A up by one position. The first element
** becomes the last element. Does nothing if the stack has less than 2 elements.
** This is one of the allowed operations in the push_swap algorithm.
*/
void	ra(t_list *a)
{
	a -> rotate(a);		/* Execute the rotate operation */
	ft_printf("ra\n");	/* Output the operation name */
}
