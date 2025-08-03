/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:21:36 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:34:35 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** sb - Swap the first two elements of stack B
** @b: Pointer to stack B
**
** Swaps the first two elements at the top of stack B. Does nothing
** if the stack has less than 2 elements. This is one of the allowed
** operations in the push_swap algorithm.
*/
void	sb(t_list *b)
{
	b -> swap(b);		/* Execute the swap operation */
	ft_printf("sb\n");	/* Output the operation name */
}
