/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:01:48 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/03 21:30:32 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct s_opt
{
	int	alt : 1;
	int	left : 1;
	int	sign : 1;
	int	space : 1;
	int	zero_pad : 1;
	int	format : 8;
	int	width;
	int	precision;
}	t_opt;

// options_parser.c

int	parse_opt(const char *format, t_opt *opt);
#endif
