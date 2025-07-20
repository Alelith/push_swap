/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:04:10 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/18 23:14:02 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_element(t_list *self, int index)
{
	if (index < 0 || index >= self -> length)
	{
		ft_printf("Index out of range: %i\n", index);
		self -> clean(self);
		exit(EXIT_FAILURE);
	}
	return (self -> elements[index]);
}
