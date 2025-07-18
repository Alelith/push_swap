/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:02:03 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/15 18:36:13 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*reallocation(void *ptr, unsigned long new_size)
{
	void			*new_ptr;

	if (ptr == 0)
		return (callocation(new_size, 1));
	if (new_size == 0)
	{
		free(ptr);
		return (0);
	}
	new_ptr = callocation(new_size, 1);
	if (new_ptr == 0)
		return (0);
	memcopy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}
