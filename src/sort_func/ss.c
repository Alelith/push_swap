/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:22:17 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:34:35 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ss - Swap the first two elements of both stacks simultaneously
** @a: Pointer to stack A
** @b: Pointer to stack B
**
** Performs sa and sb operations at the same time. Swaps the first two
** elements at the top of both stacks. This is one of the allowed operations
** in the push_swap algorithm and is more efficient than separate sa and sb.
*/
void	ss(t_list *a, t_list *b)
{
	a -> swap(a);		/* Execute swap operation on stack A */
	b -> swap(b);		/* Execute swap operation on stack B */
	ft_printf("ss\n");	/* Output the operation name */
}
