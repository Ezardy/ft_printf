/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:36:54 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/08 20:54:36 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_INT_H
# define PRINT_INT_H
# include "ft_printf.h"

int	print_int_10(long value, t_opt *opt);
int	print_int_16(long value, t_opt *opt, int lowercase);
int	print_pointer(void *p, t_opt *opt);

typedef struct s_render
{
	size_t			value;
	char			*sign;
	unsigned int	sign_len;
	char			*base_signs;
	unsigned int	base;
}	t_render;
#endif
