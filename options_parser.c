/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:13:22 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/03 22:02:01 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_flags(const char *format, t_opt *opt);
static int	parse_width(const char *format, t_opt *opt);
static int	parse_precision(const char *format, t_opt *opt);
static int	parse_specifier(const char *format, t_opt *opt);

int	parse_opt(const char *format, t_opt *opt)
{
	int	offset;
	int	local_offset;
	int	(*parse_seq[4])(const char *, t_opt *);
	int	i;

	offset = 0;
	parse_seq[0] = parse_flags;
	parse_seq[1] = parse_width;
	parse_seq[2] = parse_precision;
	parse_seq[3] = parse_specifier;
	local_offset = 0;
	if (*format++ == '%')
	{
		i = 0;
		while (local_offset > -1 && i < 4)
		{
			local_offset = parse_seq[i++](format + offset, opt);
			if (local_offset > -1)
				offset += local_offset;
			else
				offset = local_offset;
		}
	}
	return (offset);
}

static int	parse_flags(const char *format, t_opt *opt)
{

}
