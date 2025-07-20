/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:02:03 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/19 23:07:37 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*reallocation(void *ptr, unsigned long new_size, unsigned long old_size)
{
	void			*new_ptr;

	if (!ptr)
		return (callocation(new_size, 1));
	new_ptr = callocation(new_size, 1);
	if (new_ptr == 0)
		return (0);
	if (new_size > old_size)
		memcopy(new_ptr, ptr, old_size);
	else
		memcopy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}
