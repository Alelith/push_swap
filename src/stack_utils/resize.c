/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:24:59 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:47:22 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** resize - Resize the list's internal array to accommodate a new length
** @list: Pointer to the list structure to resize
** @new_len: New length for the list's elements array
**
** Resizes the list's elements array to the specified new length using the
** custom reallocation function. Preserves existing data up to the smaller
** of the old and new sizes. This function is called whenever elements are
** added or removed from the list to maintain optimal memory usage and
** prevent buffer overflows. Essential for dynamic list operations.
*/
void	resize(t_list *list, int new_len)
{
	/* Reallocate elements array with new size, preserving existing data */
	list -> elements = reallocation(list -> elements,
			sizeof(int) * new_len, sizeof(int) * list -> length);
}
