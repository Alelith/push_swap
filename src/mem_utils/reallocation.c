/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:02:03 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:31 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** reallocation - Reallocate memory with new size
** @ptr: Pointer to previously allocated memory
** @new_size: New size for the memory block
** @old_size: Previous size of the memory block
**
** Reallocates the memory block pointed to by ptr to have new_size bytes.
** If ptr is NULL, behaves like callocation. The old data is preserved
** up to the minimum of old_size and new_size. The old memory block
** is freed after copying data to the new block.
**
** Return: Pointer to reallocated memory, or NULL if allocation fails
*/
void	*reallocation(void *ptr, unsigned long new_size, unsigned long old_size)
{
	void			*new_ptr;	/* Pointer to newly allocated memory */

	/* If ptr is NULL, behave like calloc */
	if (!ptr)
		return (callocation(new_size, 1));
	
	/* Allocate new memory block */
	new_ptr = callocation(new_size, 1);
	if (new_ptr == 0)
		return (0);		/* Return NULL if allocation fails */
	
	/* Copy data from old block to new block */
	if (new_size > old_size)
		memcopy(new_ptr, ptr, old_size);	/* Copy all old data */
	else
		memcopy(new_ptr, ptr, new_size);	/* Copy only what fits */
	
	free(ptr);			/* Free old memory block */
	return (new_ptr);
}
