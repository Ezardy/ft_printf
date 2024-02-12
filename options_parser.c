/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:13:22 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/12 14:24:23 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static int	parse_flags(const char *format, t_opt *opt);
static int	parse_width(const char *format, t_opt *opt);
static int	parse_precision(const char *format, t_opt *opt);
static int	parse_specifier(const char *format, t_opt *opt);

int	parse_opt(const char *format, t_opt *opt)
{
	int	offset;

	offset = 1;
	if (*format == '%')
	{
		offset += parse_flags(format + offset, opt);
		if (opt->ens_sign)
			opt->space = 0;
		offset += parse_width(format + offset, opt);
		offset += parse_precision(format + offset, opt);
		offset += parse_specifier(format + offset, opt);
		if (opt->left || (ft_strchr("diuxX", opt->format) && opt->precision))
			opt->pad = ' ';
		if (ft_strchr("cdipsu", opt->format))
			opt->alt = 0;
	}
	else
		opt->format = *format;
	return (offset);
}

static int	parse_flags(const char *format, t_opt *opt)
{
	int	offset;
	int	flag_exists;

	offset = 0;
	flag_exists = 1;
	while (flag_exists)
	{
		offset++;
		if (*format == '#')
			opt->alt = 1;
		else if (*format == '0')
			opt->pad = '0';
		else if (*format == '-')
			opt->left = 1;
		else if (*format == ' ')
			opt->space = 1;
		else if (*format == '+')
			opt->ens_sign = 1;
		else
		{
			flag_exists = 0;
			offset--;
		}
	}
	return (offset);
}

static int	parse_width(const char *format, t_opt *opt)
{
	int	offset;

	if (ft_isdigit(*format))
	{
		opt->width = ft_atoi(format);
		offset = num_places_pos(opt->width);
		while (*(format + offset) == '0')
			offset++;
	}
	else
		offset = 0;
	return (offset);
}

static int	parse_precision(const char *format, t_opt *opt)
{
	int	offset;

	if (*format++ == '.')
	{
		offset = 1;
		if (ft_isdigit(*format))
		{
			opt->precision = ft_atoi(format);
			offset += num_places_pos(opt->precision);
			while (*(format + offset) == '0')
				offset++;
		}
	}
	else
		offset = 0;
	return (offset);
}

static int	parse_specifier(const char *format, t_opt *opt)
{
	int	offset;

	if (ft_strchr("cspdiuxX%", *format))
	{
		offset = 1;
		opt->format = *format;
		if (!(*format == 's' || *format == 'c'))
			opt->precision = 0;
		if (*format == 'p')
			opt->alt = 1;
	}
	else
	{
		offset = 0;
		opt->error = 1;
	}
	return (offset);
}
