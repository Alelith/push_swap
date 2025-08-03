/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:21:37 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:20:03 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** PUSH_SWAP - Main entry point
** 
** This file contains the main function and helper functions for the push_swap
** program. The program takes a list of integers as arguments and sorts them
** using only two stacks (A and B) with a specific set of allowed operations.
**
** The goal is to sort the numbers in stack A in ascending order using the
** minimum number of operations possible.
*/

#include "push_swap.h"

/*
** print_stack - Debug function to display stack contents
** @lst: Pointer to the list/stack to print
**
** Prints each element in the stack along with its position.
** Used for debugging and verification purposes.
*/
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

/*
** fill_list - Parse and validate input numbers
** @list: Pointer to the list to fill with numbers
** @fill_nums: String containing space-separated numbers
**
** Splits the input string by spaces and converts each part to a long integer.
** Validates that all numbers are within INT_MIN and INT_MAX range.
** Adds valid numbers to the list.
**
** Return: 1 if all numbers are valid integers, 0 if any long values found
*/
static int	fill_list(t_list *list, char *fill_nums)
{
	int		i;
	long	temp;
	int		has_long;
	char	**numbers;

	i = 0;
	has_long = 0;
	numbers = ft_split(fill_nums, ' ');		/* Split string by spaces */
	while (numbers && numbers[i])
	{
		temp = ft_atol(numbers[i]);		/* Convert to long for validation */
		if (temp > INT_MAX || temp < INT_MIN)	/* Check integer overflow */
			has_long = 1;
		else
			list -> add(list, temp);	/* Add valid number to list */
		free(numbers[i]);			/* Free individual string */
		i++;
	}
	free(numbers);					/* Free array of strings */
	return (!has_long);				/* Return 1 if no overflow detected */
}

/*
** exit_sort - Clean up and exit with error
** @a: Pointer to stack A
** @b: Pointer to stack B  
** @message: Error message to display
**
** Prints the error message, cleans up both stacks (freeing memory),
** and exits the program with failure status.
** Used for error handling throughout the program.
*/
static void	exit_sort(t_list *a, t_list *b, const char *message)
{
	ft_printf(message);			/* Print error message */
	a -> clean(a);				/* Free stack A memory */
	b -> clean(b);				/* Free stack B memory */
	exit(EXIT_FAILURE);			/* Exit with error status */
}

/*
** main - Entry point of the push_swap program
** @argc: Number of command line arguments
** @argv: Array of command line argument strings
**
** Initializes two stacks (A and B), validates input arguments,
** fills stack A with the provided numbers, checks for duplicates,
** and calls the sorting algorithm. Handles various error conditions
** including invalid arguments, integer overflow, and duplicate values.
**
** Return: 1 on successful completion
*/
int	main(int argc, char **argv)
{
	int		i;
	t_list	a;			/* Stack A - main stack to be sorted */
	t_list	b;			/* Stack B - auxiliary stack for sorting */

	i = 0;
	a = new_list();			/* Initialize stack A with methods */
	b = new_list();			/* Initialize stack B with methods */
	
	/* Check if at least one argument provided */
	if (argc < 2)
		exit_sort(&a, &b, "Invalid argument");
	
	/* Process each argument (skip program name at argv[0]) */
	while (i++ < argc)
		if (!fill_list(&a, argv[i]))	/* Fill list and check for overflow */
			exit_sort(&a, &b, "You cannot use long numbers");
	
	/* Check for duplicate values in the input */
	if (a.has_duplicated(&a))
		exit_sort(&a, &b, "This set contains duplicated values");
	
	/* Execute the sorting algorithm */
	sort(&a, &b);
	
	/* Clean up memory before exit */
	a.clean(&a);
	b.clean(&b);
	return (1);
}
