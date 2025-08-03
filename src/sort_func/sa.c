/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:16:02 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:34:34 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** sa - Swap the first two elements of stack A
** @a: Pointer to stack A
**
** Swaps the first two elements at the top of stack A. Does nothing
** if the stack has less than 2 elements. This is one of the allowed
** operations in the push_swap algorithm.
*/
void	sa(t_list *a)
{
	a -> swap(a);		/* Execute the swap operation */
	ft_printf("sa\n");	/* Output the operation name */
}
