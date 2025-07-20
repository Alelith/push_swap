/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:21:37 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/20 10:35:59 by acesteve         ###   ########.fr       */
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
	ft_printf("%s\n", fill_nums);
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
	t_list	a;
	t_list	b;

	if (argc != 2)
		return (0);
	a = new_list();
	b = new_list();
	fill_list(&a, argv[1]);
	sort(&a, &b);
	print_stack(&a);
	ft_printf("a\n<------------------------------->\nb\n");
	print_stack(&b);
	a.clean(&a);
	b.clean(&b);
	return (1);
}
