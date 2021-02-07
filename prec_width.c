/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:11:11 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:38 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_sup_width(char *str, t_flags flags, int tempw)
{
	int count;

	count = 0;
	if (flags.precision > flags.width)
	{
		if (str[0] == '-')
			count += ft_printminus(str);
		while ((tempw-- - flags.precision - 1 > 0)
				&& flags.width > flags.precision)
			count += ft_putchar(' ');
	}
	else
	{
		while ((tempw-- - flags.precision - 1 > 0)
				&& flags.width > flags.precision)
			count += ft_putchar(' ');
		if (str[0] == '-')
			count += ft_printminus(str);
		else
			count += ft_putchar(' ');
	}
	return (count);
}

int		prec_width_lj(char *str, t_flags flags, int tempp, int tempw)
{
	int count;
	int minus;

	count = 0;
	minus = 0;
	if (flags.precision >= (int)ft_strlen(str))
	{
		if (str[0] == '-' && minus++ == 0)
			count += ft_printminus(str);
		count += manage_min(str, tempp);
	}
	count += ft_putstr(str);
	if (flags.precision > (int)ft_strlen(str))
		if (minus)
			count += neg(flags, tempw);
		else
			count += pos(flags, tempw);
	else
	{
		while ((tempw-- - (int)ft_strlen(str) > 0)
			&& flags.width > flags.precision)
			count += ft_putchar(' ');
	}
	return (count);
}

int		prec_width_zf(char *str, t_flags flags, int tempp, int tempw)
{
	int count;

	count = 0;
	if (flags.precision >= (int)ft_strlen(str))
	{
		count += prec_sup_width(str, flags, tempw);
	}
	else
	{
		while ((tempw-- - (int)ft_strlen(str) > 0)
			&& flags.width > flags.precision)
			count += ft_putchar(' ');
	}
	while ((tempp-- - (int)ft_strlen(str)) > 0)
		count += ft_putchar('0');
	count += ft_putstr(str);
	return (count);
}

int		prec_width(char *str, t_flags flags)
{
	int count;
	int tempp;
	int tempw;

	count = 0;
	tempp = flags.precision;
	tempw = flags.width;
	if (flags.left_justify == 1)
	{
		count += prec_width_lj(str, flags, tempp, tempw);
	}
	else if (flags.zero_fill == 1)
	{
		count += prec_width_zf(str, flags, tempp, tempw);
	}
	else
	{
		count += prec_width_zf(str, flags, tempp, tempw);
	}
	return (count);
}
