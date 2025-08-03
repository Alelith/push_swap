/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:46:17 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:34:31 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** rr - Rotate both stacks A and B upward simultaneously
** @a: Pointer to stack A
** @b: Pointer to stack B
**
** Performs ra and rb operations at the same time. Shifts all elements
** of both stacks up by one position. The first element of each stack
** becomes the last element. This is one of the allowed operations
** in the push_swap algorithm and is more efficient than separate ra and rb.
*/
void	rr(t_list *a, t_list *b)
{
	a -> rotate(a);		/* Execute rotate operation on stack A */
	b -> rotate(b);		/* Execute rotate operation on stack B */
	ft_printf("rr\n");	/* Output the operation name */
}
