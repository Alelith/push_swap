/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:21:37 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/22 11:29:08 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *lst)
{
	int	i;

	i = 0;
	while (i < lst -> length)
	{
		ft_printf("pos: %i; num: %i\n", i, lst -> get(lst, i));
		i++;
	}
}

static int	fill_list(t_list *list, char *fill_nums)
{
	int		i;
	long	temp;
	int		has_long;
	char	**numbers;

	i = 0;
	has_long = 0;
	numbers = ft_split(fill_nums, ' ');
	while (numbers && numbers[i])
	{
		temp = ft_atol(numbers[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			has_long = 1;
		else
			list -> add(list, temp);
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (!has_long);
}

static void	exit_sort(t_list *a, t_list *b, const char *message)
{
	ft_printf(message);
	a -> clean(a);
	b -> clean(b);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	a;
	t_list	b;

	i = 0;
	a = new_list();
	b = new_list();
	if (argc < 2)
		exit_sort(&a, &b, "Invalid argument");
	while (i++ < argc)
		if (!fill_list(&a, argv[i]))
			exit_sort(&a, &b, "You cannot use long numbers");
	if (a.has_duplicated(&a))
		exit_sort(&a, &b, "This set contains duplicated values");
	sort(&a, &b);
	a.clean(&a);
	b.clean(&b);
	return (1);
}
