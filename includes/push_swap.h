/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:21:40 by acesteve          #+#    #+#             */
/*   Updated: 2025/07/17 20:23:33 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <stdlib.h>

typedef struct s_list
{
	/*Attributes*/
	int		*elements;
	int		length;

	/*Methods*/
	void	(*add)(struct s_list*, int);
	void	(*delete)(struct s_list*, int);
	void	(*clean)(struct s_list*);
	int		(*get)(struct s_list*, int);
	void	(*push)(struct s_list*, struct s_list*);
	void	(*swap)(struct s_list*);
	void	(*rotate)(struct s_list*);
	void	(*rev_rotate)(struct s_list*);
	int		(*get_smallest)(struct s_list*);
	int		(*sorted)(struct s_list*);
}	t_list;

/*Aux func*/
int				ft_atoii(const char *nptr);
unsigned long	ft_strlen(const char *s);
unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start,
					unsigned long len);
char			**ft_split(char const *s, char c);

/*Memory functions*/
void			*memcopy(void *dest, const void *src, unsigned long n);
void			*callocation(unsigned long nmemb, unsigned long size);
void			*reallocation(void *ptr, unsigned long new_size);

/*Sort functions*/
void			brute_force(t_list *a, t_list *b);
void			sa(t_list *a);
void			sb(t_list *b);
void			ss(t_list *a, t_list *b);
void			pa(t_list *a, t_list *b);
void			pb(t_list *a, t_list *b);
void			ra(t_list *a);
void			rb(t_list *b);
void			rr(t_list *a, t_list *b);
void			rra(t_list *a);
void			rrb(t_list *b);
void			rrr(t_list *a, t_list *b);

/*List methods*/
t_list			new_list(void);
void			resize(t_list *list, int new_len);
void			add_element(t_list *self, int new);
void			clean_list(t_list *self);
void			delete_element(t_list *self, int index);
int				get_element(t_list *self, int index);
void			push_element(t_list *self, t_list *other);
void			rotate_list(t_list *self);
void			rev_rotate_list(t_list *self);
void			swap_list(t_list *self);
int				get_smallest_element(t_list *self);
int				is_sorted(t_list *self);

#endif