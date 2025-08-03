/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:41:27 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:34:39 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** clean_list - Free all memory used by the list and reset it
** @self: Pointer to the list structure to clean
**
** Frees the dynamically allocated elements array and resets the list
** to an empty state. This prevents memory leaks and ensures proper cleanup.
** Does nothing if the list is NULL or already empty.
*/
void	clean_list(t_list *self)
{
	if (!self || !(self -> length))		/* Check for NULL or empty list */
		return ;
	free(self -> elements);			/* Free the elements array */
	self -> elements = 0;			/* Reset pointer to NULL */
	self -> length = 0;			/* Reset length to zero */
}
