/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:41:27 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/18 23:14:02 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_list(t_list *self)
{
	if (!self || !(self -> length))
		return ;
	free(self -> elements);
	self -> elements = 0;
	self -> length = 0;
}
