/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:11:45 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:25:42 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIS.C - Longest Increasing Subsequence implementation
**
** This file implements the Longest Increasing Subsequence (LIS) algorithm
** which is crucial for the push_swap optimization. The LIS represents
** the longest sequence of elements that are already in ascending order
** and don't need to be moved. By keeping these elements in place,
** we minimize the number of operations needed to sort the array.
**
** Algorithm: Uses dynamic programming with binary search optimization
** to achieve O(n log n) time complexity.
*/

#include "push_swap.h"

/*
** lower_bound_int - Binary search for insertion position
** @tails_vals: Array of tail values (sorted)
** @len: Length of the array
** @x: Value to find position for
**
** Finds the position where x should be inserted to maintain sorted order.
** This is equivalent to std::lower_bound in C++.
**
** Return: Index where x should be inserted
*/
static int	lower_bound_int(int *tails_vals, int len, int x)
{
	int	lo;		/* Lower bound of search range */
	int	hi;		/* Upper bound of search range */
	int	mid;		/* Middle point for binary search */

	lo = 0;
	hi = len;
	while (lo < hi)
	{
		mid = (lo + hi) / 2;
		if (tails_vals[mid] >= x)
			hi = mid;		/* Search in left half */
		else
			lo = mid + 1;		/* Search in right half */
	}
	return (lo);
}

/*
** build_lis_result - Reconstruct the LIS from computed data
** @arr: Original array/list
** @tails: 2D array containing LIS computation data
** @length: Length of the LIS found
**
** Reconstructs the actual LIS sequence by backtracking through the
** computed data structures. The tails array contains:
** - tails[0]: tail values for each LIS length
** - tails[1]: indices of tail elements
** - tails[2]: previous element indices (for backtracking)
**
** Return: New list containing the LIS elements in order
*/
static t_list	build_lis_result(t_list *arr, int **tails, int length)
{
	t_list	result;		/* Result list to return */
	int		*out;		/* Array to store LIS elements */
	int		idx;		/* Current index for backtracking */
	int		pos;		/* Position in output array */

	result = new_list();
	out = callocation(length, sizeof(int));	/* Allocate space for LIS elements */
	if (!out)
		return (result);			/* Return empty list if allocation fails */
	
	/* Start from the last element of the LIS */
	idx = tails[1][length - 1];			/* Index of last LIS element */
	pos = length - 1;				/* Position in output array */
	
	/* Backtrack through the LIS using the previous element links */
	while (pos >= 0)
	{
		out[pos] = arr -> elements[idx];	/* Store the actual value */
		idx = tails[2][idx];			/* Move to previous element */
		pos = pos - 1;
	}
	
	/* Set up result list */
	result.length = length;
	result.elements = out;
	
	/* Clean up temporary arrays */
	free(tails[0]);
	free(tails[1]);
	free(tails[2]);
	free(tails);
	return (result);
}

/*
** init_aux - Initialize auxiliary arrays for LIS computation
** @n: Size of the input array
** @tails: Pointer to 2D array to be allocated
**
** Allocates and initializes the auxiliary data structures needed for
** LIS computation:
** - tails[0]: Array to store tail values for each LIS length
** - tails[1]: Array to store indices of tail elements
** - tails[2]: Array to store previous element indices (for reconstruction)
**
** Return: 1 on success, 0 on allocation failure
*/
static int	init_aux(int n, int ***tails)
{
	*tails = callocation(3, sizeof(int *));		/* Allocate array of 3 pointers */
	if (!*tails)
		return (0);
	
	/* Allocate first auxiliary array (tail values) */
	tails[0][0] = callocation(n, sizeof(int));
	if (!tails[0][0])
		return (0);
	
	/* Allocate second auxiliary array (tail indices) */
	tails[0][1] = callocation(n, sizeof(int));
	if (!tails[0][1])
	{
		free(tails[0][0]);			/* Clean up on failure */
		return (0);
	}
	
	/* Allocate third auxiliary array (previous element links) */
	tails[0][2] = callocation(n, sizeof(int));
	if (!tails[0][2])
	{
		free(tails[0][0]);			/* Clean up on failure */
		free(tails[0][1]);
		return (0);
	}
	return (1);					/* Success */
}

/*
** process_element - Process a single element for LIS computation
** @arr: Input array/list
** @i: Index of current element to process
** @length: Pointer to current LIS length (updated by this function)
** @tails: Auxiliary arrays for LIS computation
**
** Processes element at index i in the LIS algorithm:
** 1. Finds where the element should be placed using binary search
** 2. Updates the tail arrays with new information
** 3. Links the element to its predecessor for reconstruction
** 4. Extends LIS length if element extends the sequence
**
** Return: 0 (always successful)
*/
static int	process_element(t_list *arr, int i, int *length, int **tails)
{
	int	x;		/* Current element value */
	int	k;		/* Position where element should be placed */

	x = arr -> get(arr, i);				/* Get current element value */
	k = lower_bound_int(tails[0], *length, x);	/* Find insertion position */
	
	/* Update auxiliary arrays */
	tails[0][k] = x;				/* Update tail value at position k */
	tails[1][k] = i;				/* Update tail index at position k */
	tails[2][i] = tails[1][k - 1];			/* Link to previous element */
	
	/* If we're extending the LIS, increase its length */
	if (k == *length)
		*length = *length + 1;
	return (0);
}

/*
** lis - Compute Longest Increasing Subsequence
** @arr: Input array/list to find LIS in
**
** Implements the LIS algorithm using dynamic programming with binary search
** optimization. The algorithm works by maintaining arrays of tail elements
** for increasing subsequences of each possible length. For each element,
** it finds the optimal position using binary search and updates the
** data structures accordingly.
**
** Time complexity: O(n log n)
** Space complexity: O(n)
**
** Return: New list containing the LIS elements in order
*/
t_list	lis(t_list *arr)
{
	int		**tails;		/* 2D array for LIS computation */
	int		i;			/* Loop counter */
	int		length;			/* Current LIS length */
	t_list	result;			/* Result list to return */

	tails = 0;
	i = 0;
	length = 0;
	result = new_list();
	
	/* Handle empty input */
	if (arr -> length <= 0)
		return (result);
	
	/* Initialize auxiliary data structures */
	if (!init_aux(arr -> length, &tails))
	{
		if (tails)
			free(tails);		/* Clean up on failure */
		return (result);
	}
	
	/* Process each element in the input array */
	while (i < arr -> length)
	{
		process_element(arr, i, &length, tails);
		i++;
	}
	
	/* Build and return the result */
	result = build_lis_result(arr, tails, length);
	return (result);
}
