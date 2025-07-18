/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:40:25 by acesteve          #+#    #+#             */
/*   Updated: 2025/06/16 21:34:20 by acesteve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

typedef enum e_modtype
{
	ALIGN = '-',
	SIGN = '+',
	WIDTH = 0,
	SPACE = ' ',
	ZERO = '0',
	PREC = '.',
	ALT = '#'
}	t_flgtype;

typedef struct s_modlst
{
	t_flgtype			type;
	int					value;
	struct s_modlst		*next;
}	t_flglst;

int				ft_printf(char const *str, ...);
int				ft_printdec(double num, char type);
int				ft_printchar(char c, t_flglst *flags);
int				ft_printstr(char *str, t_flglst *flags);
int				ft_printnbr(int nbr, char type, t_flglst *flags);
int				ft_printhex(unsigned long hex, char type, t_flglst *flags);
int				ft_putdouble_fd(double d, int fd);
int				ft_putoct_fd(unsigned int n, int fd);
int				ft_putexp_fd(int e, int fd, int upp);
int				ft_putnbr_fd(int n, int fd, t_flglst *flags);
int				ft_putchar_fd(char c, int fd, t_flglst *flags);
int				ft_putstr_fd(char *s, int fd, t_flglst *flags);
int				ft_putsign_fd(t_flglst *flags, int fd, int sign);
int				ft_putunbr_fd(unsigned int n, int fd, t_flglst *flags);
int				ft_puthex_fd(unsigned long p, int fd, int upp, t_flglst *flags);
int				ft_isflag(char c);
int				ft_isdigit(char c);
int				ft_isupper(char c);
int				ft_isspecifier(char c);
int				ft_intlen(int num);
int				ft_octlen(unsigned int num);
int				ft_uintlen(unsigned int num);
int				ft_hexlen(unsigned long num);
int				ft_atoi(const char **nptr);
unsigned long	ft_strlen(const char *s);
void			ft_flgclear(t_flglst **lst);
void			ft_flgadd_back(t_flglst **lst, t_flglst *new);
void			ft_flgadd_front(t_flglst **lst, t_flglst *new);
t_flglst		*ft_flgfind(t_flglst *lst, t_flgtype type);
t_flglst		*ft_flgnew(t_flgtype type, int value);

#endif