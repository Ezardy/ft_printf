/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:01:48 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/08 20:57:26 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct s_opt
{
	int		alt : 1;
	int		left : 1;
	int		ens_sign : 1;
	int		space : 1;
	int		pad : 8;
	int		format : 8;
	int		error : 12;
	int		width;
	int		precision;
}	t_opt;

// options_parser.c

int		parse_opt(const char *format, t_opt *opt);
// output.c

void	ft_putchar(char c);
void	ft_putnchar(char c, size_t n);
void	ft_putstrn(char *str, size_t n);
void	ft_putstr(char *str);
// ft_putnbr_base.c

void	ft_putnbr_base(long nbr, char *base);
// print_string.c

int		print_string(char *str, t_opt *opt);
int		print_char(char c, t_opt *opt);
// print_int.c

int	print_pointer(void *p, t_opt *opt);
int		print_int_10(int value, t_opt *opt);
int		print_int_16(int value, t_opt *opt, int lowercase);
#endif
