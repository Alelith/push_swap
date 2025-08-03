/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:40:25 by acesteve          #+#    #+#             */
/*   Updated: 2025/08/03 15:19:36 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FT_PRINTF - Custom implementation of printf function
** 
** This header contains function prototypes and structures for a custom
** printf implementation that supports various format specifiers and flags.
** The implementation handles formatting flags like alignment, padding,
** precision, and different number bases (decimal, hexadecimal, octal).
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

/*
** Enumeration defining the different types of formatting flags
** supported by the printf implementation.
*/
typedef enum e_modtype
{
	ALIGN = '-',	/* Left-align output (default is right-align) */
	SIGN = '+',	/* Always show sign for numbers */
	WIDTH = 0,	/* Minimum field width */
	SPACE = ' ',	/* Pad positive numbers with space instead of + */
	ZERO = '0',	/* Pad with zeros instead of spaces */
	PREC = '.',	/* Precision specifier */
	ALT = '#'	/* Alternative format (0x for hex, etc.) */
}	t_flgtype;

/*
** Structure representing a linked list of formatting flags.
** Each node contains a flag type and its associated value.
** Used to store multiple flags that can be applied to a format specifier.
*/
typedef struct s_modlst
{
	t_flgtype			type;	/* Type of formatting flag */
	int					value;	/* Value associated with the flag */
	struct s_modlst		*next;	/* Pointer to next flag in list */
}	t_flglst;

/* ============================================================================
** MAIN PRINTF FUNCTIONS
** ============================================================================ */

/* Main printf function - processes format string and arguments */
int				ft_printf(char const *str, ...);

/* Print decimal number with floating point support */
int				ft_printdec(double num, char type);

/* Print single character with formatting flags */
int				ft_printchar(char c, t_flglst *flags);

/* Print string with formatting flags */
int				ft_printstr(char *str, t_flglst *flags);

/* Print integer number with specified type and flags */
int				ft_printnbr(int nbr, char type, t_flglst *flags);

/* Print hexadecimal number with specified case and flags */
int				ft_printhex(unsigned long hex, char type, t_flglst *flags);

/* ============================================================================
** LOW-LEVEL OUTPUT FUNCTIONS
** File descriptor output functions for different data types
** ============================================================================ */

/* Output double to file descriptor */
int				ft_putdouble_fd(double d, int fd);

/* Output octal number to file descriptor */
int				ft_putoct_fd(unsigned int n, int fd);

/* Output scientific notation exponent to file descriptor */
int				ft_putexp_fd(int e, int fd, int upp);

/* Output signed integer to file descriptor with flags */
int				ft_putnbr_fd(int n, int fd, t_flglst *flags);

/* Output character to file descriptor with flags */
int				ft_putchar_fd(char c, int fd, t_flglst *flags);

/* Output string to file descriptor with flags */
int				ft_putstr_fd(char *s, int fd, t_flglst *flags);

/* Output sign character based on flags and number sign */
int				ft_putsign_fd(t_flglst *flags, int fd, int sign);

/* Output unsigned integer to file descriptor with flags */
int				ft_putunbr_fd(unsigned int n, int fd, t_flglst *flags);

/* Output hexadecimal to file descriptor with case and flags */
int				ft_puthex_fd(unsigned long p, int fd, int upp, t_flglst *flags);

/* ============================================================================
** PARSING AND VALIDATION FUNCTIONS
** Functions to parse format strings and validate characters
** ============================================================================ */

/* Check if character is a formatting flag */
int				ft_isflag(char c);

/* Check if character is a digit (0-9) */
int				ft_isdigit(char c);

/* Check if character is uppercase */
int				ft_isupper(char c);

/* Check if character is a format specifier (d, s, x, etc.) */
int				ft_isspecifier(char c);

/* ============================================================================
** UTILITY FUNCTIONS
** Helper functions for length calculation and string conversion
** ============================================================================ */

/* Calculate number of digits in integer */
int				ft_intlen(int num);

/* Calculate number of digits in octal representation */
int				ft_octlen(unsigned int num);

/* Calculate number of digits in unsigned integer */
int				ft_uintlen(unsigned int num);

/* Calculate number of digits in hexadecimal representation */
int				ft_hexlen(unsigned long num);

/* Convert string to integer, advancing pointer */
int				ft_atoi(const char **nptr);

/* Calculate length of string */
unsigned long	ft_strlen(const char *s);

/* ============================================================================
** FLAG LIST MANAGEMENT FUNCTIONS
** Functions to manage linked list of formatting flags
** ============================================================================ */

/* Clear and free entire flag list */
void			ft_flgclear(t_flglst **lst);

/* Add flag node to back of list */
void			ft_flgadd_back(t_flglst **lst, t_flglst *new);

/* Add flag node to front of list */
void			ft_flgadd_front(t_flglst **lst, t_flglst *new);

/* Find flag of specific type in list */
t_flglst		*ft_flgfind(t_flglst *lst, t_flgtype type);

/* Create new flag node with type and value */
t_flglst		*ft_flgnew(t_flgtype type, int value);

#endif