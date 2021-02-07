/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_width_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:39:52 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:34 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_width_lj_u(char *str, t_flags flags, int tempp, int tempw)
{
	int count;

	count = 0;
	if (flags.precision >= (int)ft_strlen(str))
		while ((tempp-- - (int)ft_strlen(str)) > 0)
			count += ft_putchar('0');
	count += ft_putstr(str);
	if (flags.precision > (int)ft_strlen(str))
		while ((tempw-- - flags.precision - 1 > 0)
				&& flags.width > flags.precision)
			count += ft_putchar(' ');
	else
	{
		while ((tempw-- - (int)ft_strlen(str) > 0)
			&& flags.width > flags.precision)
			count += ft_putchar(' ');
	}
	if (flags.width > flags.precision && flags.precision > (int)ft_strlen(str))
		count += ft_putchar(' ');
	return (count);
}

int		prec_width_zf_u(char *str, t_flags flags, int tempp, int tempw)
{
	int count;

	count = 0;
	if (flags.precision > (int)ft_strlen(str))
		while ((tempw-- - flags.precision - 1 > 0)
				&& flags.width > flags.precision)
			count += ft_putchar(' ');
	else
	{
		while ((tempw-- - (int)ft_strlen(str) > 0)
			&& flags.width > flags.precision)
			count += ft_putchar(' ');
	}
	if (flags.width > flags.precision && flags.precision > (int)ft_strlen(str))
		count += ft_putchar(' ');
	if (flags.precision >= (int)ft_strlen(str))
		while ((tempp-- - (int)ft_strlen(str)) > 0)
			count += ft_putchar('0');
	count += ft_putstr(str);
	return (count);
}

int		prec_width_u(char *str, t_flags flags)
{
	int count;
	int tempp;
	int tempw;

	count = 0;
	tempp = flags.precision;
	tempw = flags.width;
	if (flags.left_justify == 1)
	{
		count += prec_width_lj_u(str, flags, tempp, tempw);
	}
	else if (flags.zero_fill == 1)
	{
		count += prec_width_zf_u(str, flags, tempp, tempw);
	}
	else
	{
		count += prec_width_zf_u(str, flags, tempp, tempw);
	}
	return (count);
}
