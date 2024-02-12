/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:47:44 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/12 15:33:07 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static int	print_int(t_render *render, t_opt *opt);
static int	count_digits(size_t value, unsigned int base);

int	print_pointer(void *p, t_opt *opt)
{
	opt->alt = 1;
	return (print_int_16((long)p, opt, 1));
}

int	print_int_10(long value, t_opt *opt)
{
	t_render	render;

	render.sign_len = 1;
	if (value < 0)
		render.sign = "-";
	else if (opt->ens_sign)
		render.sign = "+";
	else if (opt->space)
		render.sign = " ";
	else
	{
		render.sign = "";
		render.sign_len = 0;
	}
	if (value < 0)
		render.value = -value;
	else
		render.value = value;
	render.base = 10;
	render.base_signs = "0123456789";
	return (print_int(&render, opt));
}

int	print_int_16(long value, t_opt *opt, int lowercase)
{
	t_render	render;

	if (opt->alt)
	{
		render.sign_len = 2;
		if (lowercase)
			render.sign = "0x";
		else
			render.sign = "0X";
	}
	else
	{
		render.sign = "";
		render.sign_len = 0;
	}
	if (lowercase)
		render.base_signs = "0123456789abcdef";
	else
		render.base_signs = "0123456789ABCDEF";
	render.base = 16;
	render.value = value;
	return (print_int(&render, opt));
}

static int	print_int(t_render *render, t_opt *opt)
{
	int	pad_len;
	int	prec_len;
	int	len;

	len = count_digits(render->value, render->base);
	prec_len = opt->precision - len;
	if (prec_len < 0)
		prec_len = 0;
	pad_len = opt->width - len - render->sign_len - prec_len;
	if (pad_len < 0)
		pad_len = 0;
	if (!opt->left)
		ft_putnchar(opt->pad, pad_len);
	ft_putstr(render->sign);
	ft_putnchar('0', prec_len);
	ft_putnbr_base(render->value, render->base_signs, 1);
	if (opt->left)
		ft_putnchar(opt->pad, pad_len);
	return (len + pad_len + prec_len + render->sign_len);
}

static int	count_digits(size_t value, unsigned int base)
{
	int	count;

	if (value == 0)
		count = 1;
	else
	{
		count = 0;
		while (value)
		{
			value /= base;
			count++;
		}
	}
	return (count);
}
