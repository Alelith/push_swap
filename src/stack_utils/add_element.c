/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:46:28 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 10:35:22 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_element(t_list *self, int new)
{
	resize(self, self -> length + 1);
	self -> elements[self -> length] = new;
	self -> length++;
}
