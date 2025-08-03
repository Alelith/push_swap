/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:31:37 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:27:43 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** pb - Push the top element of stack A to stack B
** @a: Pointer to stack A (source)
** @b: Pointer to stack B (destination)
**
** Takes the first element at the top of A and puts it at the top of B.
** Does nothing if A is empty. This operation is essential for the push_swap
** sorting algorithm, particularly during the phase where elements are
** moved from A to B to separate the LIS from other elements.
*/
void	pb(t_list *a, t_list *b)
{
	b -> push(b, a);	/* Execute the push operation from A to B */
	ft_printf("pb\n");	/* Output the operation name for verification */
}
