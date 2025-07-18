/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:21:37 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/18 17:20:09 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_list *lst)
{
	int	i;

	i = 0;
	while (i < lst -> length)
	{
		ft_printf("pos: %i; num: %i\n", i, lst -> get(lst, i));
		i++;
	}
}

static void	fill_list(t_list *list, char *fill_nums)
{
	int		i;
	char	**numbers;

	i = 0;
	numbers = ft_split(fill_nums, ' ');
	while (numbers && numbers[i])
	{
		list -> add(list, ft_atoii(numbers[i]));
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	list;
	t_list	list2;

	i = 0;
	list = new_list();
	list2 = new_list();
	fill_list(&list, argv[1]);
	brute_force(&list, &list2);
	print_stack(&list);
	list.clean(&list);
	list2.clean(&list);
	return (0);
}
