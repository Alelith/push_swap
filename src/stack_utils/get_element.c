/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:04:10 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:43:11 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** get_element - Retrieve element at specified index with bounds checking
** @self: Pointer to the list structure
** @index: Index of the element to retrieve (0-based)
**
** Safely retrieves an element from the list at the given index.
** Performs bounds checking to prevent array access violations.
** If the index is out of range, prints an error message, cleans up
** memory, and exits the program to prevent undefined behavior.
**
** Return: The integer value at the specified index
*/
int	get_element(t_list *self, int index)
{
	if (index < 0 || index >= self -> length)		/* Bounds check */
	{
		ft_printf("Index out of range: %i\n", index);	/* Error message */
		self -> clean(self);				/* Clean up memory */
		exit(EXIT_FAILURE);				/* Exit safely */
	}
	return (self -> elements[index]);			/* Return element */
}
