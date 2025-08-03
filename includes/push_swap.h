/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:21:40 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:19:43 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** PUSH_SWAP - A sorting algorithm using two stacks
** 
** This header file contains all the function prototypes, structures, and
** constants needed for the push_swap sorting algorithm. The program sorts
** a list of integers using only two stacks (A and B) and a limited set
** of operations.
**
** Allowed operations:
** - sa, sb, ss: swap the first two elements
** - pa, pb: push from one stack to another
** - ra, rb, rr: rotate (move first element to last)
** - rra, rrb, rrr: reverse rotate (move last element to first)
*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Integer limits definitions for portability */
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

/* Include custom printf library and standard library */
# include "ft_printf.h"
# include <stdlib.h>

/*
** Structure to represent a movement plan for sorting elements.
** This is used to calculate the optimal number of moves needed
** to push an element from stack B to the correct position in stack A.
*/
typedef struct s_plan
{
	int	idxb;		/* Index of element in stack B */
	int	target_idx;	/* Target index in stack A where element should go */
	int	dir_a;		/* Direction to move in stack A (1 for up, -1 for down) */
	int	dir_b;		/* Direction to move in stack B (1 for up, -1 for down) */
	int	moves_a;	/* Number of moves needed in stack A */
	int	moves_b;	/* Number of moves needed in stack B */
	int	combined;	/* Number of combined moves (rr or rrr) */
	int	rem_a;		/* Remaining moves for stack A after combined moves */
	int	rem_b;		/* Remaining moves for stack B after combined moves */
	int	total;		/* Total number of moves for this plan */
}	t_plan;

/*
** Structure representing a dynamic list/stack with associated methods.
** This implements an object-oriented approach in C, where each list
** has both data (elements, length) and methods (function pointers).
** Used to represent both stack A and stack B in the push_swap algorithm.
*/
typedef struct s_list
{
	/* Data attributes */
	int		*elements;	/* Dynamic array of integers */
	int		length;		/* Current number of elements in the list */

	/* Method pointers for list operations */
	void	(*add)(struct s_list*, int);		/* Add element to end */
	void	(*delete)(struct s_list*, int);		/* Delete element at index */
	void	(*clean)(struct s_list*);		/* Free all memory */
	void	(*push)(struct s_list*, struct s_list*);	/* Push to another list */
	void	(*swap)(struct s_list*);		/* Swap first two elements */
	void	(*rotate)(struct s_list*);		/* Rotate up (first to last) */
	void	(*rev_rotate)(struct s_list*);		/* Rotate down (last to first) */
	int		(*sorted)(struct s_list*);		/* Check if list is sorted */
	int		(*get)(struct s_list*, int);		/* Get element at index */
	int		(*smallest)(struct s_list*);		/* Get index of smallest element */
	int		(*contains)(struct s_list*, int);	/* Check if contains value */
	int		(*has_duplicated)(struct s_list*);	/* Check for duplicate values */
}	t_list;

/* ============================================================================
** AUXILIARY FUNCTIONS
** Helper functions for string manipulation and conversion
** ============================================================================ */

/* Convert string to long integer, handles overflow */
long			ft_atol(const char *nptr);

/* Calculate length of a string */
unsigned long	ft_strlen(const char *s);

/* Copy string with size limit, returns total length */
unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long size);

/* Duplicate a string, allocates memory */
char			*ft_strdup(const char *s);

/* Extract substring from given start position and length */
char			*ft_substr(char const *s, unsigned int start,
					unsigned long len);

/* Split string by delimiter character, returns array of strings */
char			**ft_split(char const *s, char c);

/* ============================================================================
** MEMORY MANAGEMENT FUNCTIONS
** Custom implementations of memory allocation and manipulation
** ============================================================================ */

/* Copy memory from source to destination */
void			*memcopy(void *dest, const void *src, unsigned long n);

/* Allocate and zero-initialize memory */
void			*callocation(unsigned long nmemb, unsigned long size);

/* Reallocate memory with new size, preserving old data */
void			*reallocation(void *ptr, unsigned long new_size,
					unsigned long old_size);

/* ============================================================================
** SORTING ALGORITHM FUNCTIONS
** Core functions that implement the push_swap sorting algorithm
** ============================================================================ */

/* Calculate optimal movement plan for element at index in stack B */
t_plan			plan_for_element(t_list *a, t_list *b, int idxb);

/* Main sorting function - implements the push_swap algorithm */
void			sort(t_list *a, t_list *b);

/* Find Longest Increasing Subsequence in array */
t_list			lis(t_list *arr);

/* ============================================================================
** STACK OPERATION FUNCTIONS
** Implementation of the allowed push_swap operations
** ============================================================================ */

/* sa: swap the first two elements of stack A */
void			sa(t_list *a);

/* sb: swap the first two elements of stack B */
void			sb(t_list *b);

/* ss: sa and sb at the same time */
void			ss(t_list *a, t_list *b);

/* pa: push the first element of B to the top of A */
void			pa(t_list *a, t_list *b);

/* pb: push the first element of A to the top of B */
void			pb(t_list *a, t_list *b);

/* ra: rotate stack A (first element becomes last) */
void			ra(t_list *a);

/* rb: rotate stack B (first element becomes last) */
void			rb(t_list *b);

/* rr: ra and rb at the same time */
void			rr(t_list *a, t_list *b);

/* rra: reverse rotate stack A (last element becomes first) */
void			rra(t_list *a);

/* rrb: reverse rotate stack B (last element becomes first) */
void			rrb(t_list *b);

/* rrr: rra and rrb at the same time */
void			rrr(t_list *a, t_list *b);

/* ============================================================================
** LIST/STACK UTILITY FUNCTIONS
** Functions for creating and manipulating the list/stack data structure
** ============================================================================ */

/* Initialize a new empty list with all method pointers set */
t_list			new_list(void);

/* Resize the list to accommodate new_len elements */
void			resize(t_list *list, int new_len);

/* Add a new element to the end of the list */
void			add_element(t_list *self, int new);

/* Clean up and free all memory used by the list */
void			clean_list(t_list *self);

/* Delete element at specified index, shifts remaining elements */
void			delete_element(t_list *self, int index);

/* Get element at specified index (bounds checked) */
int				get_element(t_list *self, int index);

/* Find and return index of smallest element in list */
int				get_smallest(t_list *self);

/* Push first element from self to other list (pa/pb operation) */
void			push_element(t_list *self, t_list *other);

/* Rotate list elements (first becomes last) */
void			rotate_list(t_list *self);

/* Reverse rotate list elements (last becomes first) */
void			rev_rotate_list(t_list *self);

/* Swap first two elements in list */
void			swap_list(t_list *self);

/* Check if list is sorted in ascending order */
int				is_sorted(t_list *self);

/* Check if list contains a specific number */
int				list_contains(t_list *self, int num);

/* Check if list contains any duplicate values */
int				contains_duplicated(t_list *self);

/* ============================================================================
** DEBUG/UTILITY FUNCTIONS
** ============================================================================ */

/* Print all elements in the stack (for debugging) */
void			print_stack(t_list *lst);

#endif