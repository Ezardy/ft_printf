/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanikin <zanikin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:18:17 by zanikin           #+#    #+#             */
/*   Updated: 2024/02/12 15:00:22 by zanikin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int	print_string(char *str, t_opt *opt);
int	print_char(char c, t_opt *opt);

int	print_char(char c, t_opt *opt)
{
	char	buf[2];

	buf[0] = c;
	buf[1] = '\0';
	opt->force_len = 1;
	return (print_string((char *)buf, opt));
}

int	print_string(char *str, t_opt *opt)
{
	int	len;
	int	pad_len;

	if (!str)
	{
		len = 6;
		str = "(null)";
	}
	else if (!opt->force_len)
		len = ft_strlen(str);
	else
		len = opt->force_len;
	if (opt->precision > -1 && len > opt->precision)
		len = opt->precision;
	pad_len = 0;
	if (opt->width > len)
		pad_len = opt->width - len;
	if (opt->left)
		ft_putstrn(str, len);
	ft_putnchar(opt->pad, pad_len);
	if (!opt->left)
		ft_putstrn(str, len);
	return (len + pad_len);
}
