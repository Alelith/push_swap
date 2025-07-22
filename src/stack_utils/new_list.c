/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:52:29 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 19:49:13 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	new_list(void)
{
	t_list	list;

	list.elements = 0;
	list.length = 0;
	list.add = add_element;
	list.delete = delete_element;
	list.clean = clean_list;
	list.get = get_element;
	list.smallest = get_smallest;
	list.swap = swap_list;
	list.push = push_element;
	list.rotate = rotate_list;
	list.rev_rotate = rev_rotate_list;
	list.sorted = is_sorted;
	list.contains = list_contains;
	list.has_duplicated = contains_duplicated;
	return (list);
}
