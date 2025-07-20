/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:24:17 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 10:10:07 by acesteve         ###   ########.fr       */
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

void	sort(t_list *a, t_list *b)
{
	int		i;
	t_plan	best;
	t_list	lis_lst;

	i = 0;
	lis_lst = lis(a);
	while (i < a -> length)
	{
		if (lis_lst.contains(&lis_lst, a -> get(a, 0)))
			ra(a);
		else
			pb(a, b);
		i++;
	}
	best = choose_best(a, b);
	ft_printf("Best idx: %i; Total moves: %i\n", best.idxb, best.total);
	lis_lst.clean(&lis_lst);
}
