/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_for_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:56:52 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:22:37 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** PLAN_FOR_ELEMENT.C - Cost calculation for moving elements
**
** This file contains functions to calculate the optimal movement plan
** for transferring an element from stack B to its correct position in stack A.
** The algorithm considers all possible rotations and chooses the most efficient
** combination to minimize total operations.
*/

#include "push_swap.h"

/*
** calculate_best - Find the best insertion position in stack A
** @a: Pointer to stack A
** @value: Value to be inserted
** @best_idx: Pointer to store index of best insertion position
** @min_idx: Pointer to store index of minimum value in stack A
**
** Finds two positions in stack A:
** 1. The smallest value that is larger than 'value' (best_idx)
** 2. The smallest value overall (min_idx) - used as fallback
*/
static void	calculate_best(t_list *a, int value, int *best_idx, int *min_idx)
{
	int	i;		/* Loop counter */
	int	v;		/* Current value being examined */
	int	best_val;	/* Best value found so far (> value) */
	int	min_val;	/* Minimum value found so far */

	i = 0;
	best_val = INT_MAX;
	min_val = INT_MAX;
	
	while (i < a -> length)
	{
		v = a -> get(a, i);
		
		/* Track minimum value and its index */
		if (v < min_val)
		{
			min_val = v;
			*min_idx = i;
		}
		
		/* Track smallest value larger than target value */
		if (v > value && v < best_val)
		{
			best_val = v;
			*best_idx = i;
		}
		i++;
	}
}

/*
** compute_target_idx - Determine where to insert value in stack A
** @a: Pointer to stack A
** @value: Value to be inserted
**
** Computes the optimal insertion position for 'value' in stack A.
** If there's a value in A that's larger than 'value', insert before
** the smallest such value. Otherwise, insert before the minimum value.
**
** Return: Index where the value should be inserted
*/
static int	compute_target_idx(t_list *a, int value)
{
	int	best_idx;	/* Index of best insertion position */
	int	min_idx;	/* Index of minimum value (fallback) */

	best_idx = -1;
	min_idx = -1;
	calculate_best(a, value, &best_idx, &min_idx);
	
	if (best_idx != -1)
		return (best_idx);	/* Found value > target, insert before it */
	else
		return (min_idx);	/* No value > target, insert before minimum */
}

/*
** calculate_moves - Calculate rotation moves needed for both stacks
** @p: Pointer to plan structure to fill
** @size_a: Size of stack A
** @size_b: Size of stack B
** @idxb: Index of element in stack B
**
** Determines the optimal rotation direction and number of moves for both stacks.
** Chooses between rotating up (positive direction) or down (negative direction)
** based on which requires fewer moves.
*/
static void	calculate_moves(t_plan *p, int size_a, int size_b, int idxb)
{
	/* Calculate moves for stack B */
	if (idxb <= size_b / 2)
	{
		p -> moves_b = idxb;		/* Rotate up (fewer moves) */
		p -> dir_b = 1;
	}
	else
	{
		p -> moves_b = size_b - idxb;	/* Rotate down (fewer moves) */
		p -> dir_b = -1;
	}
	
	/* Calculate moves for stack A */
	if (p -> target_idx <= size_a / 2)
	{
		p -> moves_a = p -> target_idx;	/* Rotate up (fewer moves) */
		p -> dir_a = +1;
	}
	else
	{
		p -> moves_a = size_a - p -> target_idx;	/* Rotate down (fewer moves) */
		p -> dir_a = -1;
	}
}

/*
** calculate_combined - Optimize moves by combining rotations
** @p: Pointer to plan structure to update
**
** When both stacks need to rotate in the same direction, we can use
** combined operations (rr or rrr) to reduce the total number of moves.
** This function calculates how many moves can be combined and how many
** individual moves remain for each stack.
*/
static void	calculate_combined(t_plan *p)
{
	if (p -> dir_a == p -> dir_b)	/* Same rotation direction */
	{
		/* Use the smaller number of moves for combined operations */
		if (p -> moves_a < p -> moves_b)
			p -> combined = p -> moves_a;
		else
			p -> combined = p -> moves_b;
		
		/* Calculate remaining individual moves */
		p -> rem_a = p -> moves_a - p -> combined;
		p -> rem_b = p -> moves_b - p -> combined;
	}
	else	/* Different directions - no optimization possible */
	{
		p -> combined = 0;
		p -> rem_a = p -> moves_a;
		p -> rem_b = p -> moves_b;
	}
}

/*
** plan_for_element - Create complete movement plan for element
** @a: Pointer to stack A
** @b: Pointer to stack B
** @idxb: Index of element in stack B to plan for
**
** Creates a complete movement plan for transferring the element at index 'idxb'
** in stack B to its correct position in stack A. Calculates:
** 1. Where the element should go in stack A (target_idx)
** 2. How many moves needed for each stack
** 3. How many moves can be combined (optimization)
** 4. Total cost of the operation
**
** Return: Complete movement plan with all costs calculated
*/
t_plan	plan_for_element(t_list *a, t_list *b, int idxb)
{
	t_plan	p;		/* Plan structure to build */
	int		size_a;		/* Size of stack A */
	int		size_b;		/* Size of stack B */
	int		value;		/* Value of element to move */

	size_a = a -> length;
	size_b = b -> length;
	value = b -> get(b, idxb);	/* Get value at index in stack B */
	
	/* Initialize plan with basic information */
	p.idxb = idxb;
	p.target_idx = compute_target_idx(a, value);	/* Find insertion position */
	
	/* Calculate movement costs */
	calculate_moves(&p, size_a, size_b, idxb);	/* Basic moves for each stack */
	calculate_combined(&p);				/* Optimize with combined moves */
	
	/* Total cost = combined moves + remaining moves + 1 push operation */
	p.total = p.combined + p.rem_a + p.rem_b + 1;
	
	return (p);
}
