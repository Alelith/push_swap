/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 22:24:59 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 10:35:28 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resize(t_list *list, int new_len)
{
	list -> elements = reallocation(list -> elements,
			sizeof(int) * new_len, sizeof(int) * list -> length);
}
