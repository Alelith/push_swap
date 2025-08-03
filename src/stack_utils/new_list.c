/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:52:29 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 16:19:20 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** new_list - Initialize a new list/stack structure
**
** Creates and initializes a new list structure with all method pointers
** set to their corresponding functions. This implements an object-oriented
** approach in C where the list has both data and associated methods.
** The list starts empty with no allocated memory.
**
** Return: Initialized list structure with all methods set
*/
t_list	new_list(void)
{
	t_list	list;		/* New list structure to initialize */

	/* Initialize data attributes */
	list.elements = 0;		/* No elements allocated initially */
	list.length = 0;		/* Length starts at zero */
	
	/* Set method pointers for list operations */
	list.add = add_element;			/* Add element to end */
	list.delete = delete_element;		/* Delete element at index */
	list.clean = clean_list;		/* Free all memory */
	list.get = get_element;			/* Get element at index */
	list.smallest = get_smallest;		/* Find smallest element */
	list.swap = swap_list;			/* Swap first two elements */
	list.push = push_element;		/* Push to another list */
	list.rotate = rotate_list;		/* Rotate elements */
	list.rev_rotate = rev_rotate_list;	/* Reverse rotate elements */
	list.sorted = is_sorted;		/* Check if sorted */
	list.contains = list_contains;		/* Check if contains value */
	list.has_duplicated = contains_duplicated;	/* Check for duplicates */
	
	return (list);
}
