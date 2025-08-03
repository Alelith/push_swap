/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:46:28 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:34:38 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** add_element - Add a new element to the end of the list
** @self: Pointer to the list structure
** @new: Integer value to add to the list
**
** Appends a new element to the end of the list. First resizes the list
** to accommodate the new element, then adds it and increments the length.
** This is used during initial setup to build the stack from input arguments.
*/
void	add_element(t_list *self, int new)
{
	resize(self, self -> length + 1);		/* Resize to fit new element */
	self -> elements[self -> length] = new;		/* Add new element at end */
	self -> length++;				/* Increment length counter */
}
