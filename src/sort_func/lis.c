/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 23:11:45 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 15:28:29 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	lower_bound_int(int *tails_vals, int len, int x)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 0;
	hi = len;
	while (lo < hi)
	{
		mid = (lo + hi) / 2;
		if (tails_vals[mid] >= x)
			hi = mid;
		else
			lo = mid + 1;
	}
	return (lo);
}

static t_list	build_lis_result(t_list *arr, int **tails, int length)
{
	t_list	result;
	int		*out;
	int		idx;
	int		pos;

	result = new_list();
	out = callocation(length, sizeof(int));
	if (!out)
		return (result);
	idx = tails[1][length - 1];
	pos = length - 1;
	while (pos >= 0)
	{
		out[pos] = arr -> elements[idx];
		idx = tails[2][idx];
		pos = pos - 1;
	}
	result.length = length;
	result.elements = out;
	free(tails[0]);
	free(tails[1]);
	free(tails[2]);
	free(tails);
	return (result);
}

static int	init_aux(int n, int ***tails)
{
	*tails = callocation(3, sizeof(int *));
	if (!*tails)
		return (0);
	tails[0][0] = callocation(n, sizeof(int));
	if (!tails[0][0])
		return (0);
	tails[0][1] = callocation(n, sizeof(int));
	if (!tails[0][1])
	{
		free(tails[0][0]);
		return (0);
	}
	tails[0][2] = callocation(n, sizeof(int));
	if (!tails[0][2])
	{
		free(tails[0][0]);
		free(tails[0][1]);
		return (0);
	}
	return (1);
}

static int	process_element(t_list *arr, int i, int *length, int **tails)
{
	int	x;
	int	k;

	x = arr -> get(arr, i);
	k = lower_bound_int(tails[0], *length, x);
	tails[0][k] = x;
	tails[1][k] = i;
	tails[2][i] = tails[1][k - 1];
	if (k == *length)
		*length = *length + 1;
	return (0);
}

t_list	lis(t_list *arr)
{
	int		**tails;
	int		i;
	int		length;
	t_list	result;

	tails = 0;
	i = 0;
	length = 0;
	result = new_list();
	if (arr -> length <= 0)
		return (result);
	if (!init_aux(arr -> length, &tails))
	{
		if (tails)
			free(tails);
		return (result);
	}
	while (i < arr -> length)
	{
		process_element(arr, i, &length, tails);
		i++;
	}
	result = build_lis_result(arr, tails, length);
	return (result);
}
