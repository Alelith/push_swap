/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_for_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:56:52 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 10:41:35 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_best(t_list *a, int value, int *best_idx, int *min_idx)
{
	int	i;
	int	v;
	int	best_val;
	int	min_val;

	i = 0;
	best_val = __INT_MAX__;
	min_val = __INT_MAX__;
	while (i < a -> length)
	{
		v = a -> get(a, i);
		if (v < min_val)
		{
			min_val = v;
			*min_idx = i;
		}
		if (v > value && v < best_val)
		{
			best_val = v;
			*best_idx = i;
		}
		i++;
	}
}

static int	compute_target_idx(t_list *a, int value)
{
	int	best_idx;
	int	min_idx;

	best_idx = -1;
	min_idx = -1;
	calculate_best(a, value, &best_idx, &min_idx);
	if (best_idx != -1)
		return (best_idx);
	else
		return (min_idx);
}

static void	calculate_moves(t_plan *p, int size_a, int size_b, int idxb)
{
	if (idxb <= size_b / 2)
	{
		p -> moves_b = idxb;
		p -> dir_b = 1;
	}
	else
	{
		p -> moves_b = size_b - idxb;
		p -> dir_b = -1;
	}
	if (p -> target_idx <= size_a / 2)
	{
		p -> moves_a = p -> target_idx;
		p -> dir_a = +1;
	}
	else
	{
		p -> moves_a = size_a - p -> target_idx;
		p -> dir_a = -1;
	}
}

static void	calculate_combined(t_plan *p)
{
	if (p -> dir_a == p -> dir_b)
	{
		if (p -> moves_a < p -> moves_b)
			p -> combined = p -> moves_a;
		else
			p -> combined = p -> moves_b;
		p -> rem_a = p -> moves_a - p -> combined;
		p -> rem_b = p -> moves_b - p -> combined;
	}
	else
	{
		p -> combined = 0;
		p -> rem_a = p -> moves_a;
		p -> rem_b = p -> moves_b;
	}
}

t_plan	plan_for_element(t_list *a, t_list *b, int idxb)
{
	t_plan	p;
	int		size_a;
	int		size_b;
	int		value;

	size_a = a -> length;
	size_b = b -> length;
	value = b -> get(b, idxb);
	p.idxb = idxb;
	p.target_idx = compute_target_idx(a, value);
	calculate_moves(&p, size_a, size_b, idxb);
	calculate_combined(&p);
	p.total = p.combined + p.rem_a + p.rem_b + 1;
	return (p);
}
