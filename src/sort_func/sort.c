/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:24:17 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 19:41:42 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_plan	choose_best(t_list *a, t_list *b)
{
	int		i;
	t_plan	p;
	t_plan	best;

	i = 1;
	best = plan_for_element(a, b, 0);
	while (i < b -> length)
	{
		p = plan_for_element(a, b, i);
		if (p.total < best.total)
			best = p;
		i++;
	}
	return (best);
}

static void	return_to_a(t_list *a, t_list *b)
{
	t_plan	best;

	while (b -> length)
	{
		best = choose_best(a, b);
		if (best.combined && best.dir_a > 0)
			while (best.combined--)
				rr(a, b);
		else if (best.combined && best.dir_a < 0)
			while (best.combined--)
				rrr(a, b);
		if (best.rem_a && best.dir_a > 0)
			while (best.rem_a--)
				ra(a);
		if (best.rem_b && best.dir_b > 0)
			while (best.rem_b--)
				rb(b);
		if (best.rem_a && best.dir_a < 0)
			while (best.rem_a--)
				rra(a);
		if (best.rem_b && best.dir_b < 0)
			while (best.rem_b--)
				rrb(b);
		pa(a, b);
	}
}

void	sort(t_list *a, t_list *b)
{
	int		i;
	int		original_len;
	t_list	lis_lst;

	i = 0;
	original_len = a -> length;
	lis_lst = lis(a);
	while (i < original_len)
	{
		if (lis_lst.contains(&lis_lst, a -> get(a, 0)))
			ra(a);
		else
			pb(a, b);
		i++;
	}
	return_to_a(a, b);
	while (!(a -> sorted(a)))
	{
		if (a -> smallest(a) < a -> length / 2)
			ra(a);
		else
			rra(a);
		i++;
	}
	lis_lst.clean(&lis_lst);
}
