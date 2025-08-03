/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:24:17 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:35 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SORT.C - Main sorting algorithm implementation
**
** This file contains the core sorting algorithm for push_swap. The algorithm
** uses the Longest Increasing Subsequence (LIS) approach combined with
** cost analysis to achieve optimal or near-optimal sorting.
**
** Algorithm overview:
** 1. Find LIS in stack A and keep those elements
** 2. Push all other elements to stack B
** 3. Calculate optimal moves to return elements from B to A
** 4. Final positioning to ensure stack A is sorted
*/

#include "push_swap.h"

/*
** choose_best - Find the best move plan for returning elements to stack A
** @a: Pointer to stack A
** @b: Pointer to stack B
**
** Iterates through all elements in stack B and calculates the cost
** of moving each element back to its correct position in stack A.
** Chooses the plan with the minimum total cost.
**
** Return: The optimal movement plan
*/
static t_plan	choose_best(t_list *a, t_list *b)
{
	int		i;		/* Iterator for stack B elements */
	t_plan	p;		/* Current plan being evaluated */
	t_plan	best;		/* Best plan found so far */

	i = 1;
	best = plan_for_element(a, b, 0);	/* Start with first element */
	
	/* Evaluate all other elements in stack B */
	while (i < b -> length)
	{
		p = plan_for_element(a, b, i);
		if (p.total < best.total)		/* Found better plan */
			best = p;
		i++;
	}
	return (best);
}

/*
** return_to_a - Execute optimal moves to return all elements from B to A
** @a: Pointer to stack A
** @b: Pointer to stack B
**
** Repeatedly finds the best move plan and executes it until stack B is empty.
** For each element, it performs the calculated rotations and pushes the
** element back to stack A. Uses combined moves (rr/rrr) when possible
** to minimize total operations.
*/
static void	return_to_a(t_list *a, t_list *b)
{
	t_plan	best;		/* Optimal plan for current iteration */

	while (b -> length)
	{
		best = choose_best(a, b);	/* Find best element to move */
		
		/* Execute combined rotations (both stacks in same direction) */
		if (best.combined && best.dir_a > 0)
			while (best.combined--)
				rr(a, b);		/* Rotate both stacks up */
		else if (best.combined && best.dir_a < 0)
			while (best.combined--)
				rrr(a, b);		/* Rotate both stacks down */
		
		/* Execute remaining rotations for stack A */
		if (best.rem_a && best.dir_a > 0)
			while (best.rem_a--)
				ra(a);			/* Rotate A up */
		
		/* Execute remaining rotations for stack B */
		if (best.rem_b && best.dir_b > 0)
			while (best.rem_b--)
				rb(b);			/* Rotate B up */
		
		if (best.rem_a && best.dir_a < 0)
			while (best.rem_a--)
				rra(a);			/* Rotate A down */
		
		if (best.rem_b && best.dir_b < 0)
			while (best.rem_b--)
				rrb(b);			/* Rotate B down */
		
		pa(a, b);			/* Push element from B to A */
	}
}

/*
** sort - Main sorting function implementing the push_swap algorithm
** @a: Pointer to stack A (contains unsorted elements)
** @b: Pointer to stack B (empty auxiliary stack)
**
** Implements the complete push_swap sorting algorithm:
** 1. Find the Longest Increasing Subsequence (LIS) in stack A
** 2. Keep LIS elements in A, push all others to B
** 3. Return elements from B to A in optimal order
** 4. Final rotation to position smallest element at top
**
** This algorithm ensures near-optimal performance for the push_swap problem.
*/
void	sort(t_list *a, t_list *b)
{
	int		i;			/* Loop counter */
	int		original_len;		/* Original length of stack A */
	t_list	lis_lst;		/* List containing LIS elements */

	i = 0;
	original_len = a -> length;
	lis_lst = lis(a);		/* Find Longest Increasing Subsequence */
	
	/* Phase 1: Separate LIS from other elements */
	while (i < original_len)
	{
		if (lis_lst.contains(&lis_lst, a -> get(a, 0)))
			ra(a);			/* Keep LIS element, rotate to bottom */
		else
			pb(a, b);		/* Push non-LIS element to B */
		i++;
	}
	
	/* Phase 2: Return elements from B to A in optimal order */
	return_to_a(a, b);
	
	/* Phase 3: Final positioning - rotate to put smallest at top */
	while (!(a -> sorted(a)))
	{
		if (a -> smallest(a) < a -> length / 2)
			ra(a);			/* Smallest in top half, rotate up */
		else
			rra(a);			/* Smallest in bottom half, rotate down */
		i++;
	}
	
	lis_lst.clean(&lis_lst);	/* Clean up LIS list memory */
}
