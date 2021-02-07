/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_width_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:26:55 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:11 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_lj_u(char *str, int tempw)
{
	int count;

	count = 0;
	count += ft_putstr(str);
	while (tempw-- - (int)ft_strlen(str) > 0)
		count += ft_putchar(' ');
	return (count);
}

int		width_zf_u(char *str, int tempw)
{
	int count;

	count = 0;
	if (str[0] == '-')
	{
		count += ft_printminus(str);
		while (tempw-- - (int)ft_strlen(str) - 1 > 0)
			count += ft_putchar('0');
		count += ft_putstr(str);
	}
	else
	{
		while (tempw-- - (int)ft_strlen(str) > 0)
			count += ft_putchar('0');
		count += ft_putstr(str);
	}
	return (count);
}

int		width_noflag_u(char *str, int tempw)
{
	int count;

	count = 0;
	if (str[0] == '-')
	{
		while (tempw-- - (int)ft_strlen(str) > 0)
			count += ft_putchar(' ');
		count += ft_putstr(str);
	}
	else
	{
		while (tempw-- - (int)ft_strlen(str) > 0)
			count += ft_putchar(' ');
		count += ft_putstr(str);
	}
	return (count);
}

int		only_width_u(char *str, t_flags flags)
{
	int count;
	int tempw;

	count = 0;
	tempw = flags.width;
	if (flags.left_justify == 1)
	{
		count += width_lj_u(str, tempw);
	}
	else if (flags.zero_fill == 1)
	{
		count += width_zf_u(str, tempw);
	}
	else
	{
		count += width_noflag_u(str, tempw);
	}
	return (count);
}
