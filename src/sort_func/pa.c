/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:30:37 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:41 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** pa - Push the top element of stack B to stack A
** @a: Pointer to stack A (destination)
** @b: Pointer to stack B (source)
**
** Takes the first element at the top of B and puts it at the top of A.
** Does nothing if B is empty. This is one of the allowed operations
** in the push_swap algorithm.
*/
void	pa(t_list *a, t_list *b)
{
	a -> push(a, b);	/* Execute the push operation */
	ft_printf("pa\n");	/* Output the operation name */
}
